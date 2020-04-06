#include <iostream>
#include <list>

#include "Tree.h"

using namespace std;

bool GetNodePath(const TreeNode *pRoot, const TreeNode *pNode, list<const TreeNode *> &path)
{
    if (pRoot == pNode)
    {
        return true;
    }

    path.push_back(pRoot);

    // 遍历当前节点的子节点
    auto iter = pRoot->m_vChildren.begin();

    while (iter < pRoot->m_vChildren.end())
    {
        if (*iter != nullptr)
        {
            if (GetNodePath(*iter, pNode, path))
            {
                // path.push_back(*iter);
                return true;
            }
        }
        iter++;
    }

    path.pop_back();

    return false;
}

const TreeNode *GetLastCommNode(
    const list<const TreeNode *> &path1,
    const list<const TreeNode *> &path2)
{
    list<const TreeNode *>::const_iterator iter1 = path1.begin();
    list<const TreeNode *>::const_iterator iter2 = path2.begin();

    const TreeNode *pLastCommNode = nullptr;
    while (iter1 != path1.end() && iter2 != path2.end())
    {
        if (*iter1 == *iter2)
        {
            pLastCommNode = *iter1;
        }
        else
        {
            break;
        }

        iter1++;
        iter2++;
    }

    return pLastCommNode;
}

const TreeNode *GetLastCommonParent(const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2)
{
    if (pRoot != nullptr && pNode1 != nullptr && pNode2 != nullptr)
    {
        list<const TreeNode *> path1;
        list<const TreeNode *> path2;

        if (GetNodePath(pRoot, pNode1, path1) &&
            GetNodePath(pRoot, pNode2, path2))
        {
            return GetLastCommNode(path1, path2);
        }
    }

    return nullptr;
}

// ====================测试代码====================
void Test(const char *testName, const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2, TreeNode *pExpected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    const TreeNode *pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if ((pExpected == nullptr && pResult == nullptr) ||
        (pExpected != nullptr && pResult != nullptr && pResult->m_nVal == pExpected->m_nVal))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
    TreeNode *pNode1 = CreateTreeNode(1);
    TreeNode *pNode2 = CreateTreeNode(2);
    TreeNode *pNode3 = CreateTreeNode(3);
    TreeNode *pNode4 = CreateTreeNode(4);
    TreeNode *pNode5 = CreateTreeNode(5);
    TreeNode *pNode6 = CreateTreeNode(6);
    TreeNode *pNode7 = CreateTreeNode(7);
    TreeNode *pNode8 = CreateTreeNode(8);
    TreeNode *pNode9 = CreateTreeNode(9);
    TreeNode *pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    TreeNode *pNode1 = CreateTreeNode(1);
    TreeNode *pNode2 = CreateTreeNode(2);
    TreeNode *pNode3 = CreateTreeNode(3);
    TreeNode *pNode4 = CreateTreeNode(4);
    TreeNode *pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    TreeNode *pNode1 = CreateTreeNode(1);
    TreeNode *pNode2 = CreateTreeNode(2);
    TreeNode *pNode3 = CreateTreeNode(3);
    TreeNode *pNode4 = CreateTreeNode(4);
    TreeNode *pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    TreeNode *pNode6 = CreateTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4()
{
    Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
