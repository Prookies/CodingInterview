#include <iostream>
#include <cstring>

using namespace std;

string ReplaceBlank(string& str)
{
    // 考虑空字符串的情况
    if(str.empty())
        return "";

    unsigned int count = 0;
    // 统计字符串中的空格数
    for(auto ch : str)
    {
        if(ch == ' ')
            count++;
    }

    if( count == 0)
        return "";

    // 复制到新的字符串中
    string newStr(str.size()+2*count,' ');

    //    cout << newStr.size() << endl;
    //    cout << newStr << endl;
    //    cout << str.size() << endl;

    //    string::iterator it_1 = newStr.begin() + str.length();
    //    string::iterator it_2 = newStr.end();

    int idx1 = str.size();
    int idx2 = newStr.size();

    while(idx1 >= 0)
    {
        if (str[idx1] != ' ')
            newStr[idx2] = str[idx1];
        else {
            newStr[idx2] = '0';
            newStr[--idx2] = '2';
            newStr[--idx2] = '%';
        }

        //cout << str[idx1];

        idx1--;
        idx2--;
        //cout << idx1 << " ";
    }
    return newStr;
}

void ReplaceBlank(char str[], int length)
{
    if (str == nullptr && length <= 0)
        return;

    int countBlank = 0;
    int oldIdx = 0;
    while(str[oldIdx] != '\0')
    {
        if(str[oldIdx++] == ' ')
            countBlank++;
    }

    int newIdx = oldIdx + 2*countBlank;
    if (newIdx > length)
        return;

    while(oldIdx >= 0 && oldIdx < newIdx)
    {
        if (str[oldIdx] != ' ')
            str[newIdx--] = str[oldIdx];
        else {
            str[newIdx--] = '0';
            str[newIdx--] = '2';
            str[newIdx--] = '%';
        }
        oldIdx--;
    }
}

// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main()
{
    string str = "we are happy .";
    string newStr = ReplaceBlank(str);
    cout << newStr << endl;

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
