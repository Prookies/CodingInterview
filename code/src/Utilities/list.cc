#include "list.h"

#include <iostream>

using namespace std;

ListNode* CreateListNode(int val)
{
    ListNode* pNode = new ListNode(val);
    return pNode;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
    {
        cout << "No Node in List!" << endl;
        return;
    }
        
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        cout << pNode->m_nVal << "\t";
        pNode = pNode->m_pNext;
    }
    printf("\nPrintList ends.\n");

}

void ConnectListNodes(ListNode *pCur, ListNode *pNext)
{
    if(pCur == nullptr)
    {
        cout << "Current Node IS NULL" << endl;
        // 非0表示非正常退出。
        exit(1);
    }
    pCur->m_pNext = pNext;
}

void DestroyList(ListNode* pHead)
{
    if(pHead == nullptr)
        return;
    // 从头部逐个删除
    ListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }

}

void AddToTail(ListNode **pHead, int value)
{
    // 创建新节点
    // 如果new失败了，也不会改变链表以前的状态
    ListNode *pNew = new ListNode(value);

    if (*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        // 遍历到末尾
        ListNode *pNode = *pHead;

        while (pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext;
        }

        pNode = pNew;
    }
}

void RemoveNode(ListNode **pHead, int value)
{
    // 应该怎样创建pHead，又应该怎样使用
    if (pHead == nullptr || *pHead == nullptr)
    {
        return;
    }

    // 这样操作有许多好处，用一个指针指定需要delete的变量
    ListNode *pToBeDeleted = nullptr;
    // 如果第一个节点就是要删除的
    if ((*pHead)->m_nVal == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        // 遍历到需要删除的节点
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr
               // pNode指向的是考查节点的前一个节点
               && pNode->m_pNext->m_nVal != value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }

        if (pToBeDeleted != nullptr)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
}
