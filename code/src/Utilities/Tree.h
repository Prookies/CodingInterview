#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int m_nVal;
    std::vector<TreeNode *> m_vChildren;
};

TreeNode *CreateTreeNode(int value);

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild);

void PrintTreeNode(const TreeNode *pNode);

void PrintTree(const TreeNode *pRoot);

void DestroyTree(TreeNode *pRoot);