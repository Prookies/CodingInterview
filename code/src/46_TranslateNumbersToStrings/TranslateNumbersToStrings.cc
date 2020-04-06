#include <iostream>
#include <string>

using namespace std;

bool GetNumber(string strNum)
{
    int num = 0;
    for (int i = 0; i < strNum.size(); i++)
    {
        num = 10 * num + strNum[i] - '0';
    }

    return num < 26 && num > 9;
}

int GetTranslationCount(int number)
{
    if (number < 0)
    {
        return 0;
    }
    string strNum = to_string(number);

    // cout << strNum << endl;
    int len = strNum.size();
    int counts[len + 1]{0};

    for (int i = len - 1; i >= 0; i--)
    {
        if (i < len - 2)
        {
            if (GetNumber(string(strNum, i, 2)))
            {
                counts[i] = counts[i + 1] + counts[i + 2];
            }
            else
            {
                counts[i] = counts[i + 1];
            }
        }
        else if (i < len - 1)
        {
            if (GetNumber(string(strNum, i, 2)))
            {
                counts[i] = 2;
            }
            else
            {
                counts[i] = 1;
            }
        }
        else
        {
            counts[i] = 1;
        }

        // cout << counts[i] << endl;
    }

    return counts[0];
}

/* int main()
{
    cout << GetTranslation(-12258) << endl;

    cout << GetNumber("123") << endl;
    return 0;
} */

// ====================测试代码====================
void Test(const string &testName, int number, int expected)
{
    if (GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
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

    return 0;
}