#include "Tree.h"

TreeNode *CreateTreeNode(int value)
{
    TreeNode *pNode = new TreeNode();
    pNode->m_nVal = value;

    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild)
{
    if (pParent != nullptr)
    {
        pParent->m_vChildren.push_back(pChild);
    }
}

void PrintTreeNode(const TreeNode *pNode)
{
    if (pNode != nullptr)
    {
        printf("value of this node is: %d.\n", pNode->m_nVal);

        printf("its children is as the following:\n");
        std::vector<TreeNode *>::const_iterator iter = pNode->m_vChildren.begin();
        while (iter < pNode->m_vChildren.end())
        {
            if (*iter != nullptr)
            {
                printf("%d\t", (*iter)->m_nVal);
            }
        }

        printf("\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode *pRoot)
{
    PrintTreeNode(pRoot);

    if (pRoot != nullptr)
    {
        std::vector<TreeNode *>::const_iterator iter = pRoot->m_vChildren.begin();
        while (iter < pRoot->m_vChildren.end())
        {
            PrintTree(*iter);
            ++iter;
        }
    }
}

void DestroyTree(TreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        std::vector<TreeNode *>::iterator iter = pRoot->m_vChildren.begin();
        while (iter < pRoot->m_vChildren.end())
        {
            DestroyTree(*iter);
            iter++;
        }

        delete pRoot;
    }
}