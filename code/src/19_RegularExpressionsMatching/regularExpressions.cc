#include <iostream>
#include <string.h>

using namespace std;

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
    // 当字符串和模板同时到达结束符时返回真
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    // 不需要判断是否会越界，不用判断，因为当pattern指向最后一个字符时，就开始返回了
    // 判断下一个字符是否为'*'
    if(*(pattern + 1) == '*')
    {
        // 当模板字符与字符串字符相同时或者
        // 模板字符为'.'，而字符串字符不为结束符
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态，找到一个能成功匹配的路径
            return matchCore(str + 1, pattern + 2)      // 表示将重复1次
            // 继续留在有限状态机的当前状态
            || matchCore(str + 1, pattern)              // 表示重复多次
            // 略过一个'*'
            || matchCore(str, pattern + 2);             // 表示不重复
        else
            // 略过一个'*'
            return matchCore(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

bool matchMy(const string str, const string pattern)
{
    if(str.empty() && pattern.empty())
        return true;

    char duplication = '\0';
    int i=0, j=0;
    while(i<str.length(), j<pattern.length())
    {
        if(str[i] == pattern[j] || str[i] == '.')
        {
            if(i+1 < str.length() && str[i+1] == '*')
            {
                duplication = str[i];
                if(i+2 < str.length())
                {
                    i = i+2;
                }
                else{
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
        }
        else if(pattern[j] == duplication || duplication == '.'){
            while(pattern[j] == duplication)
            {

                j++;
            }
            duplication = '\0';
        }
        else{
            return false;
        }
    }

    if(i!=str.length() || j!=pattern.length())
        return false;

    return true;
}

// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(matchMy(pattern, string) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void TestMy(string TestName, const string str, const string pattern, bool expect)
{
    cout << TestName << ": begin" << endl;
    cout << str << endl;
    cout << pattern << endl;

    if(matchMy(str, pattern) == expect)
        cout << "Passed!" << endl;
    else {
        cout << "Failed!" << endl;
    }
}

void testMy1()
{
    string str = "abaaa*";
    string pattern = "abaaaa";

    TestMy("Test1", str, pattern, true);
}

void testMy2()
{
    string str = "aa*aa*";
    string pattern = "aaaaaaaa";

    TestMy("Test1", str, pattern, true);
}

void testMy3()
{
    string str = "aba*ab";
    string pattern = "abaaab";

    TestMy("Test1", str, pattern, true);
}


int main()
{
//    testMy1();
//    testMy2();
//    testMy3();

//    Test("Test01", "", "", true);
//    Test("Test02", "", ".*", true);
//    Test("Test03", "", ".", false);
//    Test("Test04", "", "c*", true);
//    Test("Test05", "a", ".*", true);
//    Test("Test06", "a", "a.", false);
//    Test("Test07", "a", "", false);
//    Test("Test08", "a", ".", true);
//    Test("Test09", "a", "ab*", true);
//    Test("Test10", "a", "ab*a", false);
//    Test("Test11", "aa", "aa", true);
//    Test("Test12", "aa", "a*", true);
//    Test("Test13", "aa", ".*", true);
//    Test("Test14", "aa", ".", false);
//    Test("Test15", "ab", ".*", true);
//    Test("Test16", "ab", ".*", true);
//    Test("Test17", "aaa", "aa*", true);
//    Test("Test18", "aaa", "aa.a", false);
//    Test("Test19", "aaa", "a.a", true);
//    Test("Test20", "aaa", ".a", false);
//    Test("Test21", "aaa", "a*a", true);
//    Test("Test22", "aaa", "ab*a", false);
//    Test("Test23", "aaa", "ab*ac*a", true);
//    Test("Test24", "aaa", "ab*a*c*a", true);
//    Test("Test25", "aaa", ".*", true);
//    Test("Test26", "aab", "c*a*b", true);
//    Test("Test27", "aaca", "ab*a*c*a", true);
//    Test("Test28", "aaba", "ab*a*c*a", false);
//    Test("Test29", "bbbba", ".*a*a", true);
//    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
