#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

ListNode *MeetingNode(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
        return nullptr;

    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr)
    {
        if (pFast == pSlow)
            return pFast;

        pSlow = pSlow->m_pNext;

        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;
    }

    return nullptr;
}

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    ListNode *meetingNode = MeetingNode(pHead);
    if (meetingNode == nullptr)
        return nullptr;

    // 得到环中结点的数目
    int nodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    while (pNode1->m_pNext != meetingNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }

    // 先移动pNode1，次数为环中结点的数目
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; ++i)
        pNode1 = pNode1->m_pNext;

    // 再移动pNode1和pNode2
    ListNode *pNode2 = pHead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    return pNode1;
}

ListNode *findEntryNodeInListLoopMy(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    // 寻找相遇的节点
    ListNode *pFast = pHead;
    ListNode *pSlow = pHead;
    while (pFast->m_pNext != nullptr && pFast->m_pNext->m_pNext != nullptr)
    {
        pFast = pFast->m_pNext->m_pNext;
        pSlow = pSlow->m_pNext;
        if (pFast == pSlow)
            break;
    }

    // 链表不存在环
    if (pFast->m_pNext == nullptr || pFast->m_pNext->m_pNext == nullptr)
        return nullptr;

    pSlow = pHead;
    while (pSlow != pFast)
    {
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
    }

    return pSlow;
}

// ==================== Test Code ====================
void Test(char *testName, ListNode *pHead, ListNode *entryNode)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode *pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

void testMy(string TestName, ListNode *pHead, ListNode *pExpectNode)
{
    cout << TestName << ": ";
    // PrintList(pHead);
    ListNode *pResultNode = findEntryNodeInListLoopMy(pHead);

    if (pResultNode == pExpectNode)
        cout << "Passed!" << endl;
    else
        cout << "Failed!" << endl;
}

void testMy1()
{
    ListNode *p6 = new ListNode(6);
    ListNode *p5 = new ListNode(5, p6);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);
    p6->m_pNext = p3;

    ListNode *pHead = p1;
    testMy("Test1", pHead, p3);

    //DestroyList(pHead);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
}

void testMy2()
{
    ListNode *p6 = new ListNode(6);
    ListNode *p5 = new ListNode(5, p6);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);
    p6->m_pNext = p1;

    ListNode *pHead = p1;
    testMy("Test2", pHead, p1);

    //DestroyList(pHead);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
}

void testMy3()
{
    ListNode *p6 = new ListNode(6);
    ListNode *p5 = new ListNode(5, p6);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);
    p6->m_pNext = p5;

    ListNode *pHead = p1;
    testMy("Test3", pHead, p5);

    //DestroyList(pHead);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
}

void testMy4()
{
    ListNode *p6 = new ListNode(6);
    ListNode *p5 = new ListNode(5, p6);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);

    ListNode *pHead = p1;
    testMy("Test4", pHead, nullptr);

    // 由于这是一个环形链表，如果使用DestroyList将delete环的入口节点两次，从而出现错误。
    //DestroyList(pHead);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    testMy1();
    testMy2();
    testMy3();
    testMy4();

    return 0;
}