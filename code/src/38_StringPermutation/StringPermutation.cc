#include <iostream>

using namespace std;

void Permutation(char *pStr, char *pBegin);

void Permutation(char *pStr)
{
    if (pStr == nullptr || *pStr == '\0')
    {
        return;
    }

    Permutation(pStr, pStr);
}

void Permutation(char *pStr, char *pBegin)
{
    // 只有递归到最后一个元素才开始打印
    if (*pBegin == '\0')
    {
        cout << pStr << endl;
    }
    else
    {
        char *pTemp = pBegin;
        while (*pTemp != '\0')
        {

            // 交换第一个元素
            char ch = *pBegin;
            *pBegin = *pTemp;
            *pTemp = ch;

            // 固定第一个字符，对剩下的字符进行操作
            Permutation(pStr, pBegin + 1);

            // 对字符串进行恢复
            ch = *pBegin;
            *pBegin = *pTemp;
            *pTemp = ch;
            pTemp++;
        }
    }
}

// ====================测试代码====================
void Test(char *pStr)
{
    if (pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char *argv[])
{
    Test(nullptr);

    // 这里不能使用指针，因为是const类型的
    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    char string5[] = "abcd";
    Test(string5);

    return 0;
}