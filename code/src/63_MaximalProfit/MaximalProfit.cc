#include <iostream>

int MaxDiff(const int *numbers, unsigned length)
{
    if (numbers == nullptr && length < 2)
    {
        return 0;
    }

    // 记录先前最小的股票价格
    int min = numbers[0] < numbers[1] ? numbers[0] : numbers[1];
    // 利润可以为负吗？
    int maxProfit = numbers[1] - numbers[0];
    for (int i = 2; i < length; i++)
    {
        int profit = numbers[i] - min;
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
        if (min > numbers[i])
        {
            min = numbers[i];
        }
    }

    return maxProfit;
}

// ==================== Test Code ====================
void Test(const char *testName, const int *numbers, unsigned int length, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (MaxDiff(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    int numbers[] = {4, 1, 3, 2, 5};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

// 价格递增
void Test2()
{
    int numbers[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

// 价格递减
void Test3()
{
    int numbers[] = {16, 11, 7, 4, 2, 1};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

// 价格全部相同
void Test4()
{
    int numbers[] = {16, 16, 16, 16, 16};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 0);
}

void Test5()
{
    int numbers[] = {9, 11, 5, 7, 16, 1, 4, 2};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), 11);
}

void Test6()
{
    int numbers[] = {2, 4};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), 2);
}

void Test7()
{
    int numbers[] = {4, 2};
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), -2);
}

void Test8()
{
    Test("Test8", nullptr, 0, 0);
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
