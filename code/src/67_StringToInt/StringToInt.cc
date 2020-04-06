#include <iostream>
#include <limits>

using namespace std;

long long StrToIntCore(const char *str, bool minus);

enum Status
{
    kValid = 0,
    kInvalid
};

int g_nStatus = kValid;

int StrToInt(const char *str)
{
    g_nStatus = kInvalid;
    int num = 0;
    // 指针为空或者字符串为空
    if (str != nullptr && *str != '\0')
    {
        bool minus = 0;
        if (*str == '+')
        {
            str++;
        }
        else if (*str == '-')
        {
            minus = 1;
            str++;
        }

        if (*str != '\0')
            num = StrToIntCore(str, minus);
    }

    return num;
}

long long StrToIntCore(const char *str, bool minus)
{
    int flag = minus ? -1 : 1;
    long long num = 0;
    // long的最大值和最小值同int是一样的
    // long long min = INT_MIN;
    // long long max = INT_MAX;
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            num = num * 10 + flag * (*str - '0');
            // 不需要将INT_MAX强制转换成LONG LONG
            if ((!minus && num > INT_MAX) || (minus && num < INT_MIN))
            {
                num = 0;
                break;
            }
        }
        else
        {
            num = 0;
            break;
        }

        str++;
    }

    if (*str == '\0')
    {
        // cout << "Long Long MIN = " << LONG_LONG_MIN << endl;
        // cout << "INT MIN = " << INT_MIN << endl;
        // cout << "num = " << num << endl;
        g_nStatus = kValid;
    }

    return (int)num;
}

// ====================测试代码====================
void Test(const char *string)
{
    int result = StrToInt(string);
    if (result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char *argv[])
{
    Test(nullptr);

    Test("");

    Test("123");

    Test("+123");

    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");

    Test("+2147483649");

    Test("-21474836490");

    Test("+");

    Test("-");

    return 0;
}