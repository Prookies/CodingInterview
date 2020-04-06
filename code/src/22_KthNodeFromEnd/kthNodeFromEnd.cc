#include <iostream>
#include <exception>
#include "list.h"

using namespace std;

ListNode* findKthNodeFromEnd(ListNode** pHead, int k)
{
    // 需要问第零个的说法
    if(pHead == nullptr || k<=0)
        return nullptr;

    ListNode* pFront = *pHead;

    for(int i=1; i<k; i++)
    {
        pFront = pFront->m_pNext;
        if(pFront == nullptr)
        {
            // 也可以不输出错误，而是直接返回空指针
            throw string("k is great than the Node number of List");
        }
    }

    ListNode* pBack = *pHead;
    while(pFront->m_pNext)
    {
        pFront = pFront->m_pNext;
        pBack = pBack->m_pNext;
    }

    return pBack;
}

void TestMy(string TestName, ListNode** pHead, int k, ListNode* expectNode)
{
    cout << TestName << ": begin" << endl;

    PrintList(*pHead);

    ListNode* pResult = nullptr;

    try {
        ListNode* pResult = findKthNodeFromEnd(pHead, k);
    } catch (string e) {
        cout << e << endl;
    }

    if(expectNode == pResult)
        cout << "Passed!" << endl;
    else
        cout << "Failed!" << endl;

}

void testMy1()
{
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);

    ListNode** pHead = &p1;

    TestMy("Test1", pHead, 3, p3);

    DestroyList(*pHead);
}

void testMy2()
{
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);

    ListNode** pHead = &p1;

    TestMy("Test1", pHead, 5, p1);

    DestroyList(*pHead);
}

void testMy3()
{
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);

    ListNode** pHead = &p1;

    TestMy("Test1", pHead, 1, p5);

    DestroyList(*pHead);
}

void testMy4()
{
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);

    ListNode** pHead = &p1;

    TestMy("Test1", pHead, 6, nullptr);

    DestroyList(*pHead);
}

int main()
{
    testMy1();
    testMy2();
    testMy3();
    testMy4();
}
