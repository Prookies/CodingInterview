#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void)
{

}

template <typename T>
CQueue<T>::CQueue::~CQueue<T>()
{

}

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    // 此时stack2为空
    if(stack2.empty())
    {
        // 则将stack1中的数据压入到stack2中
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    // 如果stack2仍为空，则认为没有数据
    if(stack2.empty())
    {
        throw "queue is empty";
    }

    T result = stack2.top();
    stack2.pop();
    return result;

}
