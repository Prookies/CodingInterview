#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

static bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double PowerMy(double base, int exponent)
{
    // 浮点数使用==和!=是不安全的
    if(equal(base, 0.) && exponent >= 0)
        return 0;

    double result = 1.0;
    if(exponent >= 0)
    {
        for(int i=0; i<exponent; i++)
        {
            result*=base;
        }
    }
    else{
        if(!equal(base, 0.))
        {
            for(int i=0; i<-exponent; i++)
            {
                result*=base;
            }
            result = 1./result;
        }
        else{
            throw string("Valid Input!");
        }

    }


    return  result;

}


double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base,0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.;
    }

    unsigned int absExponent = static_cast<unsigned int> (exponent);
    if(exponent < 0)
        absExponent = static_cast<unsigned int> (-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1./result;

    return result;

}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent>>1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;

    return result;
}

bool equal(double num1, double num2)
{
    if(abs(num1-num2)<0.0000001)
        return true;
    return false;
}

// ====================测试代码====================

void TestMy(string TestName, double base, int exponent, double expect)
{
    cout << TestName << ":";

    double result = 0.;
    try {
        result = PowerMy(base, exponent);
    } catch (string &e) {
        cout << e << endl;
    }

    if(equal(expect, result))
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;

}

void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main()
{
    // 底数、指数都为正数
       Test("Test1", 2, 3, 8, false);

       // 底数为负数、指数为正数
       Test("Test2", -2, 3, -8, false);

       // 指数为负数
       Test("Test3", 2, -3, 0.125, false);

       // 指数为0
       Test("Test4", 2, 0, 1, false);

       // 底数、指数都为0
       Test("Test5", 0, 0, 1, false);

       // 底数为0、指数为正数
       Test("Test6", 0, 4, 0, false);

       // 底数为0、指数为负数
       Test("Test7", 0, -4, 0, true);

}
