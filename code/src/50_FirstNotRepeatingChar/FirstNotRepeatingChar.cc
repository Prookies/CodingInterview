#include <iostream>
#include <string>

char FirstNotRepeatingChar(const char *pString)
{
    if (pString == nullptr || *pString == '\0')
    {
        return '\0';
    }

    int temp[256]{0};

    const char *str = pString;

    while (*str != '\0')
    {
        temp[*(str++)]++;
    }

    while (*pString != '\0')
    {
        if (temp[*pString] == 1)
        {
            return *pString;
        }
        pString++;
    }

    return '\0';
}

// ====================测试代码====================
void Test(const char *pString, char expected)
{
    if (FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char *argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}