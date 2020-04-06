#include <iostream>

#include "ComplexList.h"

using namespace std;

void CloneNodes(ComplexListNode *pHead);
void ConnectSiblingNodes(ComplexListNode *pHead);
ComplexListNode *ReconnectNodes(ComplexListNode *pHead);

ComplexListNode *Clone(ComplexListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    CloneNodes(pHead);

    ConnectSiblingNodes(pHead);

    return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pCur = pHead;
    ComplexListNode *pPrev = nullptr;
    while (pCur)
    {
        pPrev = pCur;
        pCur = pCur->m_pNext;

        ComplexListNode *pNode = new ComplexListNode(pPrev->m_nVal);

        pPrev->m_pNext = pNode;
        pNode->m_pNext = pCur;
    }
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pSrc = pHead;
    ComplexListNode *pCpy = pHead->m_pNext;

    while (pSrc)
    {
        pCpy = pSrc->m_pNext;
        if (pSrc->m_pSibling)
            pCpy->m_pSibling = pSrc->m_pSibling->m_pNext;

        pSrc = pCpy->m_pNext;
    }
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pSrcCur = pHead;
    ComplexListNode *pCpyCur = pHead->m_pNext;
    ComplexListNode *pCpyHead = pCpyCur;

    pSrcCur->m_pNext = pCpyCur->m_pNext;
    pSrcCur = pSrcCur->m_pNext;
    while (pSrcCur)
    {
        /* ComplexListNode *pSrcNext = pCpyCur->m_pNext;
        if (pSrcNext)
        {
            ComplexListNode *pCpyNext = pSrcNext->m_pNext;

            pSrcCur->m_pNext = pSrcNext;
            pCpyCur->m_pNext = pCpyNext;

            pSrcCur = pSrcNext;
            pCpyCur = pCpyNext;
        }
        else
        {
            pSrcCur->m_pNext = nullptr;
            break;
        } */

        pCpyCur->m_pNext = pSrcCur->m_pNext;
        pCpyCur = pCpyCur->m_pNext;

        pSrcCur->m_pNext = pCpyCur->m_pNext;
        pSrcCur = pSrcCur->m_pNext;
    }

    return pCpyHead;
}

// ====================测试代码====================
void Test(const char *testName, ComplexListNode *pHead)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode *pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode *pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}