#include "binaryTree.h"

#include <iostream>

using namespace std;

BinaryTreeNode *CreateBinaryTreeNode(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode(value);

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNode *pNode)
{
    if (pNode != nullptr)
    {
        cout << "value of this node is: " << pNode->m_nVal << endl;

        if (pNode->m_pLeft != nullptr)
        {
            cout << "value of its left child is: " << pNode->m_pLeft->m_nVal << endl;
        }
        else
        {
            cout << "left child is nullptr." << endl;
        }

        if (pNode->m_pRight != nullptr)
        {
            cout << "value of its right child is: " << pNode->m_pRight->m_nVal << endl;
        }
        else
        {
            cout << "right child is nullptr." << endl;
        }
    }
}

void PrintTree(const BinaryTreeNode *pRoot)
{
    PrintTreeNode(pRoot);

    if (pRoot != nullptr)
    {
        if (pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if (pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        // 得到当前根节点的左子树和右子树
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        // 删除根节点
        delete pRoot;
        pRoot = nullptr;

        // 再递归删除左子树和右子树
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
