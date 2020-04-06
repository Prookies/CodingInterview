#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    else if(length == 2)
        return 1;

    vector<int> vMax(length);
    vMax[0] = 1;
    vMax[1] = 1;


    // 依次计算length之前的结果
    for(int i=2; i<length; i++)
    {
        int j = 1;
        while (j <= (i+1)/2) {
            int temp = max(i-j+1, vMax[i-j])*max(j, vMax[j-1]);
            //        cout << length-i << ":" << i << endl;
            //            cout << temp << ":" << vMax[i] << endl;
            if(temp > vMax[i])
                vMax[i] = temp;
            j++;
        }
        //        cout << "f("<< i+1 <<") = " << vMax[i] << endl;
    }

    return vMax[length-1];
}

int maxProductAfterCutting_solution2(int length)
{
    if(length < 2)
        return 0;
    else if(length == 2)
        return 1;
    else if(length == 3)
        return 2;

    //    int result = 1;
    //    while(length >= 4)
    //    {
    //        if(length >= 5)
    //        {
    //            result = 3*result;
    //            length = length - 3;
    //        }
    //        else {
    //            result = 2*result;
    //            length = length - 2;
    //        }
    //    }
    //    if(length == 2)
    //        result = 2*result;
    //    else if(length == 3)
    //        result = 3*result;

    // 尽可能多的减去长度为3的绳子
    int timeOf3 = length / 3;   // 得到3的幂次

    // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
    // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
    if(length - timeOf3*3 == 1)
        timeOf3--;

    int timeOf2 = (length - 3*timeOf3)/2;


    return static_cast<int>(pow(3,timeOf3)*pow(2,timeOf2));
}

// ====================测试代码====================
void test(const char* testName, int length, int expected)
{
    //    int result1 = maxProductAfterCutting_solution1(length);
    //    if(result1 == expected)
    //        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    //    else
    //        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main( )
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}
