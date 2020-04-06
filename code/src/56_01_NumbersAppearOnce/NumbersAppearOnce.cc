#include <iostream>

using namespace std;

bool IsBit1(int num, unsigned int idex);

void FindNumsAppearOnce(int data[], int length, int *num1, int *num2)
{
    if (data == nullptr || length < 2)
    {
        cout << "Invalid Input!" << endl;
        return;
    }

    int sum = data[0];
    for (int i = 1; i < length; i++)
    {
        sum ^= data[i];
    }

    if (sum == 0)
    {
        cout << "Invalid Input!" << endl;
        return;
    }
    // 计算位
    int digit = 0;
    int test = 1;
    while ((sum & test) == 0)
    {
        digit++;
        test = test << 1;
    }

    // 遍历数组，根据digit位是否为1来拆分数组
    *num1 = 0;
    *num2 = 0;
    for (int i = 0; i < length; i++)
    {
        if (IsBit1(data[i], digit))
        {
            (*num1) ^= data[i];
        }
        else
        {
            (*num2) ^= data[i];
        }
    }
}

bool IsBit1(int num, unsigned int idx)
{
    return num & (1 << idx);
}

// ====================测试代码====================
void Test(const char *testName, int data[], int length, int expected1, int expected2)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if ((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = {4, 6};
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = {4, 6, 1, 1, 1, 1};
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}