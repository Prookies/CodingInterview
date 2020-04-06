#include <iostream>
#include <stack>

#include "list.h"

using namespace std;

/**
 * @brief PrintListReversingly_Iteratively
 * @param pHead ListNode* 为什不用ListNode**了
 */
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    // 首先考虑特殊情况
    if (pHead == nullptr)
        return;

    stack<int> s;

    ListNode *pCur = pHead;
    while (pCur != nullptr)
    {
        s.push(pCur->m_nVal);
        pCur = pCur->m_pNext;
    }

    while(!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pNode)
{
    if(pNode == nullptr)
        return;
    PrintListReversingly_Recursively(pNode->m_pNext);
    cout << pNode->m_nVal << "\t";
}

// ====================测试代码====================
void Test(ListNode *pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode *pNode1 = new ListNode(1);
    ListNode *pNode2 = new ListNode(2);
    ListNode *pNode3 = new ListNode(3);
    ListNode *pNode4 = new ListNode(4);
    ListNode *pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode *pNode1 = new ListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}
