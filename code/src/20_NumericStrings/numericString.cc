#include <iostream>
#include <string.h>

using namespace std;

// 之所以将str改为二维指针，是因为需要传递str的位置
bool scanUnsignedIntegerMy(const char** str);
bool scanIntegerMy(const char** str);

bool isNumeric(const char* str)
{
    if(str == nullptr)
        return false;

    bool numeric = scanIntegerMy(&str);      // 判断是否为一个普通的整数

    if(*str == '.')
    {
        ++str;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedIntegerMy(&str) || numeric;
    }

    if(*str == 'e' || *str == 'E')
    {
        ++str;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanIntegerMy(&str);
    }

    return numeric && *str == '\0';
}

// 提取字符串中的整数部分
bool scanUnsignedIntegerMy(const char** str)
{

    const char* before = *str;

    while(**str != '\0' && **str >= '0' && **str <= '9')
        (*str)++;
    return  *str > before;
}

bool scanIntegerMy(const char** str)
{
    if(**str == '-' || **str == '+')
        (*str)++;

    return scanUnsignedIntegerMy(str);
}


// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}
