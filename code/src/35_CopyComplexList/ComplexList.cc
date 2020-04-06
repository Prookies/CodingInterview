#include <iostream>

#include "ComplexList.h"

using namespace std;

ComplexListNode *CreateNode(int nVal)
{
    ComplexListNode *pNode = new ComplexListNode(nVal);

    return pNode;
}

void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling)
{
    if (pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nVal);

        if (pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nVal);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}
