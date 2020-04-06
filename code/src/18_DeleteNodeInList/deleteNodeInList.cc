#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

void DeleteNodeMy(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 这个分布是不合理的，因为大多数情况满足最后一个条件
    // 需要删除的节点所在的链表是否只有一个节点
    if(!(*pListHead)->m_pNext)
    {
        if(*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        }
        else{
            throw string("Only one Node, But isn't the Node to be delete");
        }
    }
    else if(!pToBeDeleted->m_pNext)
    {
        // 需要删除的节点是否是最后一个节点
        ListNode* preNode = *pListHead;
        while(preNode->m_pNext != pToBeDeleted)
        {
            preNode = preNode->m_pNext;
            if(!preNode)
                throw string("pToBeDeleted is exist");
        }

        preNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    else{
        ListNode* tempNode = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nVal = pToBeDeleted->m_pNext->m_nVal;
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;

        delete tempNode;
        tempNode = nullptr;
    }
}

void testMy(string TestName, ListNode** pHead, ListNode* pToBeDeleted)
{
    cout << TestName << ": Begin" << endl;
    PrintList(*pHead);
    try{
        DeleteNodeMy(pHead, pToBeDeleted);
    }catch(string &e){
        cout << e << endl;
    }
    PrintList(*pHead);
}

void TestMy1()
{
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode2 = new ListNode(2, pNode3);
    ListNode* pNode1 = new ListNode(1, pNode2);

    ListNode** pHead = &pNode1;
    testMy("TestMy1", pHead, pNode1);

    DestroyList(*pHead);
}

void TestMy2()
{
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode2 = new ListNode(2, pNode3);
    ListNode* pNode1 = new ListNode(1, pNode2);

    ListNode** pHead = &pNode1;
    testMy("TestMy2", pHead, pNode3);

    DestroyList(*pHead);
}

void TestMy3()
{
    ListNode* pNode1 = new ListNode(1);

    ListNode** pHead = &pNode1;
    testMy("TestMy3", pHead, pNode1);

    DestroyList(*pHead);
}

int main()
{
    TestMy1();
    TestMy2();
    TestMy3();

    return 0;
}
