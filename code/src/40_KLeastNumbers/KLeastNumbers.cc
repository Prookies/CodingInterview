#include <iostream>
#include <set>
#include <vector>
#include <functional>

#include "Array.h"

using namespace std;

void GetLeastNumbers_Solution1(int *input, int n, int *output, int k)
{
    if (input == nullptr || n <= 0 || output == nullptr || k <= 0 || k > n)
    {
        return;
    }

    int begin = 0;
    int end = n - 1;
    int idx = Partition(input, n, begin, end);
    while (k != (idx + 1))
    {
        if (idx + 1 < k)
        {
            begin = idx + 1;
            idx = Partition(input, n, begin, end);
        }
        else
        {
            end = idx - 1;
            idx = Partition(input, n, begin, end);
        }
    }

    for (int i = 0; i < k; i++)
    {
        output[i] = input[i];
    }
}

void GetLeastNumbers_Solution2(int *input, int n, set<int> &output, int k)
{
    if (input == nullptr || n <= 0 || k <= 0 || k > n)
    {
        return;
    }

    // set容器中的元素都是唯一的，但是输入的元素是唯一的吗
    int max = input[0];
    for (int i = 0; i < n; i++)
    {
        if (output.size() < k)
        {
            output.insert(input[i]);
            if (input[i] > max)
            {
                max = input[i];
            }
        }
        else
        {
            if (input[i] < max)
            {
                output.erase(max);
                output.insert(input[i]);
                // 重新找最大值
                max = *output.begin();
                for (auto iter = output.begin(); iter != output.end(); iter++)
                {
                    if (*iter > max)
                    {
                        max = *iter;
                    }
                }
            }
        }
    }
}

// ====================测试代码====================
void Test(char *testName, int *data, int n, int *expectedResult, int k)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    int *Copy = new int[n];
    for (int i = 0; i < n; ++i)
        Copy[i] = data[i];

    if (expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for (int i = 0; i < k; ++i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int *output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if (expectedResult != nullptr)
    {
        for (int i = 0; i < k; ++i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    set<int> leastNumbers;
    GetLeastNumbers_Solution2(Copy, n, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for (auto iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int *expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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

    return 0;
}