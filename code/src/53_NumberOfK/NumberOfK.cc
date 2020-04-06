#include <iostream>

using namespace std;

int GetFirst(const int *data, int k, int begin, int end);
int GetLast(const int *data, int k, int begin, int end);

int GetNumberOfK(const int *data, int length, int k)
{
    if (data == nullptr || length <= 0)
    {
        cout << "Invalid Input!" << endl;
        return 0;
    }

    // 二分查找
    int begin = 0;
    int end = length - 1;
    int mid = 0;
    bool bFind = false;
    while (begin <= end)
    {
        mid = ((end - begin) >> 1) + begin;
        if (data[mid] > k)
        {
            end = mid - 1;
        }
        else if (data[mid] < k)
        {
            begin = begin + 1;
        }
        else
        {
            bFind = true;
            break;
        }
    }

    if (bFind)
    {
        int FirstIdx = 0;
        int LastIdx = length - 1;
        // 前一个数字仍为k，则在前半段继续寻找
        if (mid > 0 && data[mid - 1] == k)
        {
            FirstIdx = GetFirst(data, k, begin, mid - 1);
        }
        else
        {

            FirstIdx = mid;
        }

        if (mid + 1 < length && data[mid + 1] == k)
        {
            LastIdx = GetLast(data, k, mid + 1, end);
        }
        else
        {
            LastIdx = mid;
        }
        return LastIdx - FirstIdx + 1;
    }

    return 0;
}

int GetFirst(const int *data, int k, int begin, int end)
{
    // 使用二分查找
    while (begin <= end)
    {
        int mid = ((end - begin) >> 1) + begin;
        if (data[mid] > k)
        {
            end = mid - 1;
        }
        else if (data[mid] < k)
        {
            begin = begin + 1;
        }
        else
        {
            if (mid > 0 && data[mid - 1] == k)
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }

    return 0;
}

int GetLast(const int *data, int k, int begin, int end)
{
    // 使用二分查找
    while (begin <= end)
    {
        int mid = ((end - begin) >> 1) + begin;
        if (data[mid] > k)
        {
            end = mid - 1;
        }
        else if (data[mid] < k)
        {
            begin = begin + 1;
        }
        else
        {
            if (mid + 1 <= end && data[mid + 1] == k)
            {
                begin = mid + 1;
            }
            else
            {
                return mid;
            }
        }
    }

    return 0;
}

// ====================测试代码====================
void Test(const char *testName, int data[], int length, int k, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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
    Test9();
    Test10();
    Test11();

    return 0;
}