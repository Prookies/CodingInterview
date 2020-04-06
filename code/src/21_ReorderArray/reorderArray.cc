#include <iostream>

using namespace std;

void ReorderMy(int *pData, unsigned int length, bool (*func)(int));
void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// ====================方法一====================
void ReorderOddEven_1(int *pData, unsigned int length)
{
    if(pData == nullptr || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // 向后移动pBegin，直到它指向偶数
        while(pBegin < pEnd && (*pBegin & 0x1) != 0)
            pBegin ++;

        // 向前移动pEnd，直到它指向奇数
        while(pBegin < pEnd && (*pEnd & 0x1) == 0)
            pEnd --;

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}


void ReorderOddEvenMy_1(int *pData, unsigned int length)
{
    if(pData == nullptr || length == 0)
    {
        return;
    }

    int* pBegin = pData;
    int* pEnd = pData+length-1;

    while(pEnd > pBegin)
    {
        // 这里应该考虑一下该数组交换的次数多不多，多的话，交换就应该放在前面
        if(isEven(*pEnd)&&!isEven(*pBegin))
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;

            pBegin++;
            pEnd--;
        }
        else{
            // 可以把这一步改成while循环，是pBegin和pEnd到达指定位置。然后直接交换就可以了。

            if(isEven(*pBegin))
                pBegin++;

            if(!isEven(*pEnd))
                pEnd--;
        }
    }
}

void ReorderOddEvenMy_2(int* pData, unsigned int length)
{
    if(pData == nullptr || length == 0)
        return;

    auto isOdd = [](int num)->bool {return num&1;};

    ReorderMy(pData, length, isOdd);

}

void ReorderMy(int* pData, unsigned int length, bool (*func)(int) )
{

    int* pBegin = pData;
    int* pEnd = pData + length - 1;


    while(pEnd > pBegin)
    {
        // 移动指针到指定的位置
        while(pEnd>pBegin && func(*pBegin))
            pBegin++;

        while(pEnd>pBegin && !func(*pEnd))
            pEnd--;

        if(pEnd > pBegin)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}




bool isEven(int n)
{
    if(n & 1)
        return true;

    return false;
}

// ====================测试代码====================
void PrintArray(int numbers[], unsigned int length)
{
    if(length == 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], unsigned int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEvenMy_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEvenMy_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", nullptr, 0);
}

void TestMy(string TestName, int* pData, unsigned int length)
{

    cout << TestName << ": begin" << endl;
    for(int i=0; i<length; i++)
        cout << pData[i] << " ";
    cout << endl;

    ReorderOddEvenMy_2(pData, length);

    for(int i=0; i<length; i++)
        cout << pData[i] << " ";
    cout << endl;

}

void testMy1()
{
    int pData[] = {1,2,3,4,5};

    TestMy("Test1", pData, 5);
}

void testMy2()
{
    int pData[] = {4,7,8,9,11};

    TestMy("Test2", pData, 5);
}

int main()
{
    testMy1();
    testMy2();

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}
