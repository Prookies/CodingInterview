#pragma once

struct ListNode
{
    int         m_nVal;
    ListNode*   m_pNext;
    ListNode(int val, ListNode* pNode=nullptr) : m_nVal(val), m_pNext(pNode){}
};

ListNode* CreateListNode(int val);
void PrintList(ListNode* pHead);
void ConnectListNodes(ListNode* pCur, ListNode* pNext);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int val);
void RemoveNode(ListNode **pHead, int value);

