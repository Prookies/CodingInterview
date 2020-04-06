#include <set>
#include <deque>
#include <iostream>

using namespace std;

bool IsUgly(int number)
{
    while ((number % 2) == 0)
    {
        number /= 2;
    }

    while ((number % 3) == 0)
    {
        number /= 3;
    }

    while ((number % 5) == 0)
    {
        number /= 5;
    }

    return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
    if (index <= 0)
    {
        cout << "Valid Input!" << endl;
        return 0;
    }

    int number = 0;
    int count = 0;
    while (count < index)
    {
        number++;
        if (IsUgly(number))
        {
            count++;
        }
    }

    return number;
}

int GetUglyNumber_Solution2(int index)
{
    if (index <= 0)
    {
        cout << "Valid Input!" << endl;
        return 0;
    }

    // 逐个选择最小的丑数，可以参考答案
    // 选择x2,x3,x5的位置
    int idx2 = 0;
    int idx3 = 0;
    int idx5 = 0;

    int UglyNums[index]{0};
    UglyNums[0] = 1;
    for (int i = 1; i < index; i++)
    {
        // 选择出最小的丑数
        int min = 0;
        min = (2 * UglyNums[idx2] < 3 * UglyNums[idx3]) ? 2 * UglyNums[idx2] : 3 * UglyNums[idx3];
        min = (5 * UglyNums[idx5] < min) ? 5 * UglyNums[idx5] : min;

        UglyNums[i] = min;
        // 对位置进行跟新
        while (2 * UglyNums[idx2] <= UglyNums[i])
        {
            idx2++;
        }
        while (3 * UglyNums[idx3] <= UglyNums[i])
        {
            idx3++;
        }
        while (5 * UglyNums[idx5] <= UglyNums[i])
        {
            idx5++;
        }
    }

    /*     while (setUglyNums.size() < index)
    {
        int number = qTemp.front();
        qTemp.pop_front();

        qTemp.push_back(2 * number);
        setUglyNums.insert(2 * number);

        qTemp.push_back(3 * number);
        setUglyNums.insert(3 * number);

        qTemp.push_back(5 * number);
        setUglyNums.insert(5 * number);

        // 补充当前最大元素前面的值
        while (qTemp.front() != *setUglyNums.rbegin())
        {
            int number = qTemp.front();
            qTemp.pop_front();
            if (2 * number < *setUglyNums.rbegin())
            {

                setUglyNums.insert(2 * number);
            }
            else if (3 * number < *setUglyNums.rbegin())
            {

                setUglyNums.insert(3 * number);
            }
            else if (5 * number < *setUglyNums.rbegin())
            {

                setUglyNums.insert(5 * number);
            }
            qTemp.push_back(2 * number);
            qTemp.push_back(3 * number);
            qTemp.push_back(5 * number);
        }
    }*/

    return UglyNums[index - 1];
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if (GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if (GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char *argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
