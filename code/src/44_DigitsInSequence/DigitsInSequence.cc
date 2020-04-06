#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int digitAtIndex(int index)
{
    if (index < 10)
    {
        return index;
    }

    int idx = index - 10;

    // 当前位数
    int digit = 1;
    do
    {
        digit++;
        // 剩余的位数
        index = idx;
        idx -= digit * 9 * pow(10, digit - 1);
    } while (idx > 0);

    int d = index / digit;
    int r = index % digit;

    int num = pow(10.0, digit - 1) + d;

    string strNum = to_string(num);

    return strNum[r] - '0';
}

// ====================测试代码====================
void test(const char *testName, int inputIndex, int expectedOutput)
{
    if (digitAtIndex(inputIndex) == expectedOutput)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

int main()
{
    test("Test1", 0, 0);
    test("Test2", 1, 1);
    test("Test3", 9, 9);
    test("Test4", 10, 1);
    test("Test5", 189, 9);  // 数字99的最后一位，9
    test("Test6", 190, 1);  // 数字100的第一位，1
    test("Test7", 1000, 3); // 数字370的第一位，3
    test("Test8", 1001, 7); // 数字370的第二位，7
    test("Test9", 1002, 0); // 数字370的第三位，0
    return 0;
}