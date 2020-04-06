#include <iostream>

using namespace std;

// 问什么形参为int[]类型的
bool VerifySquenceOfBST(int *sequence, int length)
{
    if (sequence == nullptr || length <= 0)
    {
        return false;
    }

    if (length == 1)
    {
        return true;
    }

    // 最后一个元素是根节点
    // 从前往后遍历，观察是否有小于根节点的元素
    int idxRight = 0;

    for (int i = 0; i < length - 1; i++)
    {
        if (sequence[i] < sequence[length - 1])
        {
            idxRight++;
        }
        else
        {
            break;
        }
    }

    // 接下来的元素应该都是属于右子树的
    for (int i = idxRight; i < length - 1; i++)
    {
        if (sequence[i] < sequence[length - 1])
        {
            return false;
        }
    }

    if (idxRight > 0)
    {
        if (!VerifySquenceOfBST(sequence, idxRight))
        {
            return false;
        }
    }

    if (idxRight < length - 1)
    {
        if (!VerifySquenceOfBST(sequence + idxRight, length - idxRight - 1))
        {
            return false;
        }
    }

    return true;
}

// ====================测试代码====================
void Test(const char *testName, int sequence[], int length, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}