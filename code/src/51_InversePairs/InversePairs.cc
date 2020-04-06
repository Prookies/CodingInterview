#include <iostream>

using namespace std;

int InversePairsCore(int *data, int *copy, int start, int end);

int Merge(int *data, int *copy, int i, int m, int n);

// 可以参考源码，也是按照归并排序的想法来的
int InversePairs(int *data, int length)
{
    if (data == nullptr || length <= 0)
    {
        cout << "Invalid Input!" << endl;
        return 0;
    }

    return InversePairsCore(data, data, 0, length - 1);
}

int InversePairsCore(int data[], int copy[], int start, int end)
{
    int count = 0;
    int len = end - start + 1;
    int *temp = new int[len]{0};
    // 说明只有一个元素
    if (start == end)
    {
        copy[start] = data[start];
    }
    else
    {
        // 将数组平分为两半
        int mid = ((end - start) >> 1) + start;
        count += InversePairsCore(data, temp, start, mid);
        count += InversePairsCore(data, temp, mid + 1, end);
        count += Merge(temp, copy, start, mid, end);
    }

    // 有个问题是temp不能delete

    return count;
}

int Merge(int data[], int copy[], int begin, int mid, int end)
{

    int i = mid, j = end, k = end;
    int count = 0;
    // 有序数组的合并，并排序
    for (; i >= begin && j >= mid + 1; k--)
    {
        if (data[i] > data[j])
        {
            copy[k] = data[i--];
            count += (j - mid);
        }
        else
        {
            copy[k] = data[j--];
        }
    }

    for (; i >= begin; i--)
    {
        copy[k--] = data[i];
    }

    for (; j > mid; j--)
    {
        copy[k--] = data[j];
    }

    return count;
}

// ====================测试代码====================
void Test(char *testName, int *data, int length, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = {6, 5, 4, 3, 2, 1};
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = {1};
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = {1, 2};
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = {2, 1};
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = {1, 2, 1, 2, 1};
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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