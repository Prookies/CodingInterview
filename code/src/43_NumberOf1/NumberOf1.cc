#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int count = 0;

    for (unsigned int i = 1; i <= n; i++)
    {
        unsigned int number = i;

        do
        {
            if (number % 10 == 1)
            {
                count++;
            }
        } while (number /= 10);
    }

    return count;
}

int NumberOf1(vector<int> num);

int NumberOf1Between1AndN_Solution2(unsigned int n)
{
    int count = 0;
    vector<int> nums;
    do
    {
        nums.emplace_back(n % 10);
        n /= 10;
    } while (n);

    count = NumberOf1(vector<int>(nums.rbegin(), nums.rend()));

    /* for (auto riter = nums.rbegin(); riter != nums.rend(); riter++)
    {
        cout << *riter << " ";
    } */

    return count;
}

int NumberOf1(vector<int> nums)
{
    /* for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl; */

    int count = 0;

    if (nums.size() > 1)
    {
        // 从1到999...(n-1个)的计数
        count += (nums.size() - 1) * pow(10.0, nums.size() - 2);

        if (nums[0] > 1)
        {
            // 从100...(n位)到199...(n位)的计数
            count *= 2;
            count += pow(10.0, (nums.size() - 1));
            // 从200...(n位)到(n[0]-1)99...(n位)的计数
            count += (nums[0] - 2) * (nums.size() - 1) * pow(10.0, nums.size() - 2);
            // 从n[0]00...到n的计数
            int idx = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[idx] != 0)
                {
                    break;
                }
                idx++;
            }
            if (idx < nums.size())
                count += NumberOf1(vector<int>(nums.begin() + idx, nums.end()));
        }
        else
        {
            for (int i = 1; i < nums.size(); i++)
            {
                count += nums[i] * pow(10.0, nums.size() - i - 1);
            }
            count++;

            int idx = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[idx] != 0)
                {
                    break;
                }
                idx++;
            }
            if (idx < nums.size())
                count += NumberOf1(vector<int>(nums.begin() + idx, nums.end()));
        }
    }
    else
    {
        if (nums[0] != 0)
            count = 1;
    }

    return count;
}

// ====================测试代码====================
void Test(const char *testName, int n, int expected)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    if (NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if (NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char *argv[])
{
    Test();

    // cout << NumberOf1Between1AndN_Solution2(21345) << endl;

    // cout << (int)pow(10.0, 3) << endl;
    return 0;
}