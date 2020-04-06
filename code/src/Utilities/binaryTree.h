#pragma once

struct BinaryTreeNode
{
    int m_nVal;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode(int x) : m_nVal(x), m_pLeft(nullptr), m_pRight(nullptr) {}
};

BinaryTreeNode *CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);
void PrintTreeNode(const BinaryTreeNode *pNode);
void PrintTree(const BinaryTreeNode *pRoot);
void DestroyTree(BinaryTreeNode *pRoot);
