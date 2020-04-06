#pragma once

struct ComplexListNode
{
    int m_nVal;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
    ComplexListNode(int val) : m_nVal(val), m_pNext(nullptr), m_pSibling(nullptr) {}
};

ComplexListNode *CreateNode(int nVal);
void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext,
                ComplexListNode *pSiblint);
void PrintList(ComplexListNode *pHead);