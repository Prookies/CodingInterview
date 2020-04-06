#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

void DeleteDuplication(ListNode** pHead)
{
    if(!pHead)
        return;

    ListNode* curNode = *pHead;
    ListNode* preNode = nullptr;
    int duplicationVal = curNode->m_nVal;
    while(curNode && curNode->m_pNext)
    {
        duplicationVal = curNode->m_nVal;
        if(curNode->m_pNext->m_nVal == duplicationVal)
        {
            while(curNode && curNode->m_nVal == duplicationVal)
            {
                if(curNode != *pHead)
                {
                    ListNode* deletedNode = curNode;
                    curNode = curNode->m_pNext;
                    delete deletedNode;
                    deletedNode = nullptr;
                }
                else{
                    ListNode* deletedNode = *pHead;
                    *pHead = (*pHead)->m_pNext;
                    curNode = *pHead;
                    delete deletedNode;
                    deletedNode = nullptr;

                }
            }

        }
        else{
            preNode = curNode;
            curNode = curNode->m_pNext;
        }
        if(preNode)
            preNode->m_pNext = curNode;
    }
}

void TestMy(string TestName, ListNode** pHead)
{
    cout << TestName << ": begin" << endl;

    PrintList(*pHead);
    DeleteDuplication(pHead);
    PrintList(*pHead);
}

void testMy1()
{
    ListNode* pNode6 = new ListNode(5);
    ListNode* pNode5 = new ListNode(4, pNode6);
    ListNode* pNode4 = new ListNode(4, pNode5);
    ListNode* pNode3 = new ListNode(3, pNode4);
    ListNode* pNode2 = new ListNode(3, pNode3);
    ListNode* pNode1 = new ListNode(2, pNode2);
    ListNode* pNode0 = new ListNode(1, pNode1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

void testMy2()
{
    ListNode* pNode6 = new ListNode(3);
    ListNode* pNode5 = new ListNode(2, pNode6);
    ListNode* pNode4 = new ListNode(2, pNode5);
    ListNode* pNode3 = new ListNode(2, pNode4);
    ListNode* pNode2 = new ListNode(1, pNode3);
    ListNode* pNode1 = new ListNode(1, pNode2);
    ListNode* pNode0 = new ListNode(1, pNode1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

void testMy3()
{
    ListNode* pNode6 = new ListNode(7);
    ListNode* pNode5 = new ListNode(6, pNode6);
    ListNode* pNode4 = new ListNode(5, pNode5);
    ListNode* pNode3 = new ListNode(4, pNode4);
    ListNode* pNode2 = new ListNode(3, pNode3);
    ListNode* pNode1 = new ListNode(2, pNode2);
    ListNode* pNode0 = new ListNode(1, pNode1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

void testMy4()
{

    ListNode* pNode0 = new ListNode(1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

void testMy5()
{

    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1, pNode6);
    ListNode* pNode4 = new ListNode(1, pNode5);
    ListNode* pNode3 = new ListNode(1, pNode4);
    ListNode* pNode2 = new ListNode(1, pNode3);
    ListNode* pNode1 = new ListNode(1, pNode2);
    ListNode* pNode0 = new ListNode(1, pNode1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

void testMy6()
{

    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode4 = new ListNode(3, pNode5);
    ListNode* pNode3 = new ListNode(2, pNode4);
    ListNode* pNode2 = new ListNode(2, pNode3);
    ListNode* pNode1 = new ListNode(1, pNode2);
    ListNode* pNode0 = new ListNode(1, pNode1);

    ListNode** pHead = &pNode0;

    TestMy("Test1", pHead);

    DestroyList(*pHead);
}

int main()
{
    testMy1();
    testMy2();
    testMy3();
    testMy4();
    testMy5();
    testMy6();

    return 0;
}
