#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
class DynamicArray
{
public:
    void Insert(T num)
    {

        if ((min.size() + max.size()) & 1)
        {
            // 为奇数时插入最小堆。
            // 其是否大于最小堆的最小元素
            if (min.size() > 0 && min[0] < num)
            {
                min.emplace_back(num);
                // 把最小的元素放在第一个元素
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                // 将最小的元素移到最后一个元素
                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            // 把最小的元素给最大栈
            max.emplace_back(num);
            // 将最大的元素放到第一个元素
            push_heap(max.begin(), max.end(), less<T>());
        }
        else
        {
            if (max.size() > 0 && max[0] > num)
            {
                max.emplace_back(num);
                // 把最大的元素移到第一个元素
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                // 将最大的元素移到最后一个元素
                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            // 把最大的元素给最小栈
            min.emplace_back(num);
            // 将最小的元素放到首位
            push_heap(min.begin(), min.end(), greater<T>());
        }
    }
    T GetMedian()
    {
        if ((min.size() + max.size()) == 0)
        {
            throw string("No numbers are available");
        }
        if ((min.size() + max.size()) & 1)
        {
            if (min.size() > max.size())
            {
                return min[0];
            }
            else
            {
                return max[0];
            }
        }
        else
        {
            return (max[0] + min[0]) / 2;
        }
    }

private:
    vector<T> min;
    vector<T> max;
};

/* int main()
{
    vector<int> vTemp{7, 2, 3, 1, 4, 6};

    // 把最大的放在前面
    push_heap(vTemp.begin(), vTemp.end(), greater<int>());

    for (int num : vTemp)
    {
        cout << num << " ";
    }
    cout << endl;
} */

// ====================测试代码====================
void Test(char *testName, DynamicArray<double> &numbers, double expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char *argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch (const string &e)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}