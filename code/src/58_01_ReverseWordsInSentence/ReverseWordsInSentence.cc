#include <iostream>
#include <string.h>

#include "StringUtil.h"

using namespace std;

char *ReverseSentence(char *pData)
{
    if (pData == nullptr)
    {
        return nullptr;
    }
    else if (*pData == '\0')
    {
        return "";
    }

    // cout << pData << endl;
    char *pEnd = pData;

    while (*pEnd != '\0')
    {
        pEnd++;
    }

    char *pBegin = pData;

    Reverse(pData, pEnd - 1);

    // cout << pData << endl;

    pEnd = pData;
    while (*pEnd != '\0')
    {
        ++pEnd;
        if (*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, pEnd - 1);
            if (*pEnd == '\0')
            {
                break;
            }
            pBegin = ++pEnd;
        }
    }
    // cout << pData << endl;

    return pData;
}

// ====================测试代码====================
void Test(const char *testName, char *input, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if ((input == nullptr && expectedResult == nullptr) || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}