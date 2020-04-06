#include <iostream>
#include <deque>
#include <exception>

using namespace std;

template <typename T>
class QueueWithMax
{
public:
    QueueWithMax() : currentIndex(0)
    {
    }

    // 感觉达不到O(1)的时间复杂度
    void push_back(T number)
    {
        // 队列是一种后进后出的数据结构
        // 如果插入的元素的值大于前面的元素的值，
        // 那么该队列前面小于该插入元素的值的元素的最大值则为该元素。
        while (!maximums.empty() && number >= maximums.back().number)
        {
            maximums.pop_back();
        }

        currentIndex++;
        struct InternalData temp = {number, currentIndex};

        maximums.push_back(temp);
        data.push_back(temp);
    }

    void pop_front()
    {
        if (!maximums.empty() && !data.empty())
        {
            InternalData max = maximums.front();
            InternalData cur = data.front();

            if (max.index == cur.index)
            {
                maximums.pop_front();
            }

            data.pop_front();
        }
    }

    T max() const
    {
        if (!maximums.empty())
        {
            return maximums.front().number;
        }

        throw "Dequeue is empty!";
    }

private:
    struct InternalData
    {
        T number;
        int index;
    };

    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndex;
};

// ====================测试代码====================
void Test(const char *testName, const QueueWithMax<int> &queue, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char *argv[])
{
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}