#include <map>
#include <string>
#include <iostream>

using namespace std;

int longestSubstringWithoutDuplication(const std::string &str)
{
    if (str.empty())
    {
        return 0;
    }

    // 上一个重复的字符
    int nBeginIdx = 0;
    // 最大的长度
    int nLongest = 0;
    // 当前长度
    int nLen = 0;

    // 记录每个字符
    map<char, int> visited;

    for (int i = 0; i < str.size(); i++)
    {
        // 不是重复的字符
        if (visited.find(str[i]) == visited.end())
        {
            visited.insert(make_pair(str[i], i));
            nLen++;
        }
        else
        {

            if (nBeginIdx > visited[str[i]])
            {

                nLen++;
            }
            else
            {
                // 如果开始索引的小于等于重复字符的索引
                // 则说明重复的字符在正在检测的字符串里面
                if (nLen > nLongest)
                {
                    // 更新最长的长度
                    nLongest = nLen;
                }
                // 改变长度
                nLen = nLen - (visited[str[i]] - nBeginIdx);
                // 改变起始位置
                nBeginIdx = nBeginIdx + (visited[str[i]] - nBeginIdx) + 1;
            }

            visited[str[i]] = i;
        }
    }

    return nLen > nLongest ? nLen : nLongest;
}

// ====================测试代码====================
void testSolution1(const std::string &input, int expected)
{
    int output = longestSubstringWithoutDuplication(input);
    if (output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

// void testSolution2(const std::string &input, int expected)
// {
//     int output = longestSubstringWithoutDuplication_2(input);
//     if (output == expected)
//         std::cout << "Solution 2 passed, with input: " << input << std::endl;
//     else
//         std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
// }

void test(const std::string &input, int expected)
{
    testSolution1(input, expected);
    // testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}