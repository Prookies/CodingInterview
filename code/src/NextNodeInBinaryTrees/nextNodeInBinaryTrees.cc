#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent;
    int64_t m_nVal;     // 为了实现对齐把int改成了int64_t
    BinaryTreeNode(int val) : m_pLeft(nullptr), m_pRight(nullptr), m_pParent(nullptr), m_nVal(val) {}
};

// 尽量统一返回结果，否则程序看上去过于混乱
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }
    // 情况1：如果该节点有右子树，则它的下一个节点就是其右子节点的最后一个左子节点
    BinaryTreeNode* pNext = nullptr;
    if(pNode->m_pRight != nullptr)
    {
        pNext = pNode->m_pRight;
        while(pNext->m_pLeft != nullptr)
        {
            pNext = pNext->m_pLeft;
        }
    }
    else if (pNode->m_pParent != nullptr)   // 父节点不为空
    {
        // 情况2：如果该节点无右子树，且其是其父节点的左子节点，该情况下面的循环也考虑了这种情况
        //        if(pNode->m_pParent->m_pLeft == pNode)
        //        {
        //            // 其父节点就是当前节点的下一个节点
        //            return pNode->m_pParent;
        //        }
        //        else {
        // 情况3： 其是其父节点的右子节点，
        BinaryTreeNode *pCur = pNode;
        pNext = pNode->m_pParent;
        // while(pNext->m_pLeft != pCur && pNext != nullptr)是错误的
        // 因为如果其先对pNext->m_pLeft != pCur进行判断，再对pNext != nullptr进行判断
        // 如果此时pNext为nullptr了，那么前面的判断就没有意义了，系统便会报错
        // 所以条件判断一定要注意先后顺序，注意是否有关联
        while(pNext != nullptr && pNext->m_pLeft != pCur)
        {
            pCur = pNext;
            pNext = pNext->m_pParent;
//            if(pNext == nullptr)
//                return nullptr;
        }
        //        }
    }

    return pNext;

}

// ==================== 辅助代码用来构建二叉树 ====================
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode(value);

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if(pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        // %ld用来输出long整数，%d用来输出十进制有符号整数
        printf("value of this node is: %ld\n", pNode->m_nVal);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %ld.\n", pNode->m_pLeft->m_nVal);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %ld.\n", pNode->m_pRight->m_nVal);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    Test("Test8", pNode5, nullptr);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test12", pNode5, nullptr);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void Test16()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    Test("Test16", pNode5, nullptr);

    DestroyTree(pNode5);
}

int main()
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
    return 0;
}
