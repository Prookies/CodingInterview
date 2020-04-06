#include <iostream>
#include "list.h"

using namespace std;

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
    {
        return nullptr;
    }

    // 计算两个链表的长度
    ListNode *pCur1 = pHead1, *pCur2 = pHead2;
    int nLen1 = 0, nLen2 = 0;
    while (pCur1 && pCur2)
    {
        if (pCur1 == pCur2)
        {
            return pCur1;
        }
        nLen1++;
        nLen2++;
        pCur1 = pCur1->m_pNext;
        pCur2 = pCur2->m_pNext;
    }

    while (pCur1)
    {
        nLen1++;
        pCur1 = pCur1->m_pNext;
    }

    while (pCur2)
    {
        nLen2++;
        pCur2 = pCur2->m_pNext;
    }

    if (nLen1 != nLen2)
    {
        // 长的链表先移动
        ListNode *pLong = nullptr;
        ListNode *pSmall = nullptr;
        int diff = 0;
        if (nLen1 > nLen2)
        {
            pLong = pHead1;
            pSmall = pHead2;
            diff = nLen1 - nLen2;
        }
        else
        {
            pLong = pHead2;
            pSmall = pHead1;
            diff = nLen2 - nLen1;
        }

        for (int i = 0; i < diff; i++)
        {
            pLong = pLong->m_pNext;
        }

        while (pLong && pSmall)
        {
            if (pLong == pSmall)
            {
                return pLong;
            }

            pLong = pLong->m_pNext;
            pSmall = pSmall->m_pNext;
        }
    }

    return nullptr;
}

// ====================测试代码====================
void DestroyNode(ListNode *pNode);

void Test(char *testName, ListNode *pHead1, ListNode *pHead2, ListNode *pExpected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ListNode *pResult = FindFirstCommonNode(pHead1, pHead2);
    if (pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//
// 5 - 6 - 7
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test2", pNode1, pNode5, nullptr);

    DestroyList(pNode1);
    DestroyList(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test3", pNode1, pNode5, pNode7);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合
void Test4()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test4", pNode1, pNode1, pNode1);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test5()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test5", nullptr, pNode1, nullptr);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6()
{
    Test("Test6", nullptr, nullptr, nullptr);
}

void DestroyNode(ListNode *pNode)
{
    delete pNode;
    pNode = nullptr;
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}