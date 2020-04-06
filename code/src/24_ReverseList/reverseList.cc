#include <iostream>
#include <string.h>

#include "list.h"

using namespace std;

// 是否该函数对环形链表也有效，应该是不行的，环形链表不能反转

// 只会影响pHead所指的对象，而pHead的变化并影响实参的变化
// 所以这时候的返回值很有意义
ListNode *reverseListMy1(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *prev = nullptr;
    ListNode *cur = pHead;
    ListNode *front = cur->m_pNext;
    cur->m_pNext = prev;

    while (front != nullptr)
    {
        prev = cur;
        cur = front;
        front = front->m_pNext;
        cur->m_pNext = prev;
    }

    return cur;
}

// 由于传递的是实参的地址，所以*pHead的变化会作用到实参
// 所以这里可以不需要返回值
// 这里的*pHead也就是reverseListMy的pHead
ListNode *reverseListMy2(ListNode **pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return nullptr;

    ListNode *prev = nullptr;
    ListNode *front = (*pHead)->m_pNext;
    (*pHead)->m_pNext = prev;

    while (front != nullptr)
    {
        prev = *pHead;
        *pHead = front;
        front = front->m_pNext;
        (*pHead)->m_pNext = prev;
    }

    return *pHead;
}

// 回传处理的结果，不然DestoryList无法释放整个链表
ListNode *TestMy1(string TestName, ListNode *pHead)
{
    cout << TestName << ": begin!" << endl;
    PrintList(pHead);
    // 由于这里传递的是pHead，所以pHead在函数中的变化并不会回传
    ListNode *pReverseHead = reverseListMy1(pHead);
    // 如果传递pHead则不能打印出正确的结果
    PrintList(pReverseHead);

    return pReverseHead;
}

// 由于传递的是*pHead，所以不会对实参pHead有影响
// 所以需要回传处理后的指针，否则无法释放整个链表
ListNode *TestMy2(string TestName, ListNode *pHead)
{
    cout << TestName << ": begin!" << endl;
    PrintList(pHead);
    // 由于这里传递的是地址，所以pHead也会跟着变化
    ListNode *pReverseHead = reverseListMy2(&pHead);
    // 通过pHead就可以打印出正确的结果，而不需要pReverseHead
    PrintList(pHead);
    return pReverseHead;
}

// 由于传递的是**pHead，所以会对实参*pHead有影响，所以不需要回传指针
void TestMy3(string TestName, ListNode **pHead)
{
    cout << TestName << ": begin!" << endl;
    PrintList(*pHead);
    // 由于这里传递的是地址，所以pHead也会跟着变化
    reverseListMy2(pHead);
    // 通过pHead就可以打印出正确的结果，而不需要pReverseHead
    PrintList(*pHead);
}

void testMy1()
{
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);

    ListNode *pHead = p1;
    // 由于传递的是pHead，而不是pHead的地址，所以pHead并不会发生变化
    // 所以pHead所指的对象还是以前那个对象
    ListNode *pReverseHead = TestMy1("Test1", pHead);

    // 如果TestMy函数没有传递pHead的地址，那么pHead则没有改变
    // 所以DestroyList函数使用pHead作为形参，则不会完全销毁整个链表，从而导致内存泄漏
    PrintList(pHead);

    // 如果反转之后，要考虑一下pHead有没有改变
    // 因为原先的pHead指针没有变化的话，反转之后通过pHead不能遍历所有的节点
    // 所以需要通过回传的pReverseHead指针来销毁整个链表
    DestroyList(pReverseHead);
}

void testMy2()
{
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);

    ListNode *pHead = p1;
    // 由于传递的是pHead，而不是pHead的地址，所以pHead并不会发生变化
    // 所以pHead所指的对象还是以前那个对象
    ListNode *pReverseHead = TestMy2("Test2", pHead);

    // 如果TestMy函数没有传递pHead的地址，那么pHead则没有改变
    // 所以DestroyList函数使用pHead作为形参，则不会完全销毁整个链表，从而导致内存泄漏
    PrintList(pHead);

    // 如果反转之后，要考虑一下pHead还对不对
    // 因为原先的pHead指针没有变化的话，反转之后通过pHead不能遍历所有的节点
    DestroyList(pReverseHead);
}

void testMy3()
{
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);

    ListNode *pHead = p1;
    // 如果直接使用p1的地址，那么反转之后P1所指的对象发生变化，
    // 如果需要某个实参在函数的改变则传递其地址到函数中
    TestMy3("Test3", &pHead);

    PrintList(pHead);

    // cout << p1->m_nVal << endl;
    // 此时DestoryList函数使用pHead是可行的，因为pHead已经是反转之后的链表头结点了。
    DestroyList(pHead);
}

int main()
{
    testMy1();
    testMy2();
    testMy3();
    return 0;
}
