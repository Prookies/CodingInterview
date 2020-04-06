#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const void *strNumber1, const void *strNumber2);

// 源代码的更好
void PrintMinNumber(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return;
    }

    vector<string> str;
    for (int i = 0; i < length; i++)
    {
        str.emplace_back(to_string(numbers[i]));
    }

    string result = "";
    while (str.size())
    {
        // 选出当前最小的数
        auto iterLeast = str.begin();
        for (auto iter = str.begin(); iter != str.end(); iter++)
        {
            if (compare(&(*iterLeast), &(*iter)))
            {
                iterLeast = iter;
            }
        }

        string LeastNum = *iterLeast;
        string temp1 = result + LeastNum;
        string temp2 = LeastNum + result;
        if (compare(&temp1, &temp2))
        {
            // 如果组合之后发现原先的结果加上当前的最小的值的结果小于
            // 当前最小值加上原先结果，则说明上一次选择不佳，所以重新计算。
            str.emplace_back(result);
            result = LeastNum;
        }
        else
        {
            result = temp1;
        }
        str.erase(iterLeast);
        // cout << result << endl;
    }
    cout << result << endl;
}

int compare(const void *strNumber1, const void *strNumber2)
{
    return *(const string *)strNumber1 > *(const string *)strNumber2;
}

// ====================测试代码====================
void Test(const char *testName, int *numbers, int length, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    if (expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    PrintMinNumber(numbers, length);

    printf("\n");
}

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3()
{
    int numbers[] = {3, 3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), "3212332333");
}

void Test4()
{
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6()
{
    Test("Test6", nullptr, 0, "Don't print anything.");
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}