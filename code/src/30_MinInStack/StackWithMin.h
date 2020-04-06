#pragma once

#include <stack>
#include <assert.h>

using namespace std;

template <typename T>
class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T &top();             // 不安全
    const T &top() const; // 有这个为什么还需要上面那个

    void push(const T &value);
    void pop();

    const T &min() const;

    bool empty() const;
    size_t size() const;

private:
    stack<T> m_data; // 数据栈，存放栈的所有元素
    stack<T> m_min;  // 辅助栈，存放栈的最小元素
};

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    if (!m_data.empty())
    {
        if (value < m_min.top())
        {
            m_min.push(value);
        }
        else
        {
            m_min.push(m_min.top());
        }
    }
    else
    {
        m_min.push(value);
    }

    m_data.push(value);
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(!m_data.empty());

    m_min.pop();
    m_data.pop();
}

template <typename T>
const T &StackWithMin<T>::min() const
{
    assert(!m_data.empty());

    return m_min.top();
}

template <typename T>
T &StackWithMin<T>::top()
{
    assert(!m_data.empty());

    return m_data.top();
}

template <typename T>
const T &StackWithMin<T>::top() const
{
    assert(!m_data.empty());

    return m_data.top();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T>
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}