#include <iostream>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }

    qsort(numbers, length, sizeof(int), Compare);

    // 统计数组中0个个数，统计排序之后的数组中相邻数字之间的空缺总数
    int nZeroCount = 0;
    int i = 0;
    for (; i < length; i++)
    {
        if (numbers[i] != 0)
        {
            break;
        }
        else
        {
            nZeroCount++;
        }
    }

    int nVacancyCount = 0;

    for (i++; i < length; i++)
    {
        if (numbers[i] - numbers[i - 1] > 1)
        {
            nVacancyCount += numbers[i] - numbers[i - 1] - 1;
        }
        else if (numbers[i] == numbers[i - 1])
        {
            return false;
        }
    }

    if (nVacancyCount > nZeroCount)
    {
        return false;
    }

    return true;
}

// ====================测试代码====================
void Test(const char *testName, int *numbers, int length, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int numbers[] = {1, 3, 2, 5, 4};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    int numbers[] = {1, 3, 2, 6, 4};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = {0, 3, 2, 6, 4};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = {0, 3, 1, 6, 4};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = {1, 3, 0, 5, 0};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = {1, 3, 0, 7, 0};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = {1, 0, 0, 5, 0};
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = {1, 0, 0, 7, 0};
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = {3, 0, 0, 0, 0};
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = {0, 0, 0, 0, 0};
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = {1, 0, 0, 1, 0};
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", nullptr, 0, false);
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
    Test12();

    return 0;
}

int Compare(const void *arg1, const void *arg2)
{
    return (*(int *)arg1 - *(int *)arg2);
}