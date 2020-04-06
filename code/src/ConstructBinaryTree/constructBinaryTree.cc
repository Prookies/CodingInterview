#include <iostream>
#include <exception>

#include "binaryTree.h"

using namespace std;

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
                              int *startInorder, int *endInorder);

BinaryTreeNode *Construct(int *preorder, int *inoder, int length)
{
    // 确保前向遍历和中序遍历的结果不为空，且数组长度大于0
    if (preorder == nullptr || inoder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder+length-1,
                                         inoder, inoder+length-1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
                              int *startInorder, int *endInorder)
{
    // 前序遍历序列的第一个数字是根结点的值
        int rootValue = startPreorder[0];
        BinaryTreeNode* root = new BinaryTreeNode(rootValue);

        // 前序遍历只有一个数据
        if(startPreorder == endPreorder)
        {
            // 如果只有一个数据那么前序遍历和中序遍历的结果相同
            if(startInorder == endInorder && *startPreorder == *startInorder)
                return root;
            else
                throw std::exception();
        }

        // 在中序遍历中找到根结点的值
        int* rootInorder = startInorder;
        while(rootInorder <= endInorder && *rootInorder != rootValue)
            ++ rootInorder;

        // 如果大于endInorder但是*rootInorder == rootValue怎么办
        // 所以应该改用我自己的代码
        if(rootInorder == endInorder && *rootInorder != rootValue)
            throw std::exception();

        // 两个指针相减得到长度
        int leftLength = rootInorder - startInorder;
        int* leftPreorderEnd = startPreorder + leftLength;
        if(leftLength > 0)
        {
            // 构建左子树
            root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
                startInorder, rootInorder - 1);
        }
        if(leftLength < endPreorder - startPreorder)
        {
            // 构建右子树
            root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
                rootInorder + 1, endInorder);
        }

        return root;

}

//BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
//                              int *startInorder, int *endInorder)
//{
//    // 递归的退出条件

//    // 当前树的根节点
//    BinaryTreeNode *root = new BinaryTreeNode(*startPreorder);
//    // 寻找根节点在中序遍历的位置
//    int idx = 0;
//    while (*(startInorder + idx) != *startPreorder)
//    {

//        idx++;
//        if(startInorder+idx > endInorder)
//            throw std::exception();
//    }
//    // 如果idx = 0怎么办？idx=0，则该节点没有左子树
//    // 如果idx = length怎么办？刚好根节点是中序遍历的最后一个元素，那么则该根节点没有右子树
//    cout << "根节点索引为：" << idx << endl;
//    cout << "左子树前序遍历：" << endl;
//    for (int i=1; i<=idx; i++) {
//        cout << *(startPreorder+i) << " ";
//    }
//    cout << endl;
//    cout << "左子树中序遍历：" << endl;
//    for (int i=0; i<idx; i++) {
//        cout << *(startInorder+i) << " ";
//    }
//    cout << endl;
//    cout << "右子树前序遍历：" << endl;
//    int idxRight = idx+1;
//    while ((startPreorder+idxRight)<=endPreorder) {
//        cout << *(startPreorder+idxRight) << " ";
//        idxRight++;
//    }
//    cout << endl;
//    cout << "右子树中序遍历：" << endl;
//    idxRight = idx+1;
//    while ((startInorder+idxRight)<=endInorder) {
//        cout << *(startInorder+idxRight) << " ";
//        idxRight++;
//    }
//    cout << endl;

//    if (idx > 0)
//        root->m_pLeft = ConstructCore(startPreorder + 1, startPreorder + idx,
//                                      startInorder, startInorder + idx - 1);
//    if ((startInorder + idx) < endInorder)
//        root->m_pRight = ConstructCore(startPreorder + idx + 1, endPreorder,
//                                       startInorder + idx + 1, endInorder);
//    return root;
//}

// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}
