#include <iostream>

using namespace std;

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
    if (sum < 3)
    {
        return;
    }

    int begin = 1;
    int end = 2;

    int middle = (sum + 1) / 2;
    int result = begin + end;

    while (begin <= middle)
    {
        if (result < sum)
        {
            end++;
            result += end;
        }
        else if (result > sum)
        {
            result -= begin;
            begin++;
        }
        else
        {
            PrintContinuousSequence(begin, end);
            result -= begin;
            begin++;
        }
    }
}

void PrintContinuousSequence(int small, int big)
{
    for (int i = small; i <= big; i++)
    {
        cout << i << " ";
    }

    cout << endl;
}

// ====================测试代码====================
void Test(const char *testName, int sum)
{
    if (testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

int main(int argc, char *argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}
