#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void BuildProductionArray(const vector<double> &input, vector<double> &output)
{
    int nLen1 = input.size();
    int nLen2 = output.size();
    if (nLen1 == nLen2 && nLen1 > 1)
    {
        vector<double> vTemp1;
        vector<double> vTemp2;

        vTemp1.emplace_back(1);
        vTemp2.emplace_back(1);
        for (int i = 1; i < nLen1; i++)
        {
            vTemp1.emplace_back(vTemp1.back() * input[i - 1]);
            vTemp2.emplace_back(vTemp2.back() * input[nLen1 - i]);
        }

        for (int i = 0; i < nLen2; i++)
        {
            output[i] = vTemp1[i] * vTemp2[nLen1 - i - 1];
        }
    }
}

//================= Test Code =================
static bool EqualArrays(const vector<double> &input, const vector<double> &output)
{
    int length1 = input.size();
    int length2 = output.size();

    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; ++i)
    {
        if (abs(input[i] - output[i]) > 0.0000001)
            return false;
    }

    return true;
}

static void test(char *testName, const vector<double> &input, vector<double> &output, vector<double> &expected)
{
    printf("%s Begins: ", testName);

    BuildProductionArray(input, output);
    if (EqualArrays(output, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

static void test1()
{
    // 输入数组中没有0
    vector<double> input{1, 2, 3, 4, 5};
    vector<double> output{0, 0, 0, 0, 0};
    vector<double> expected{120, 60, 40, 30, 24};

    test("Test1", input,
         output,
         expected);
}

static void test2()
{
    // 输入数组中有一个0
    vector<double> input{1, 2, 0, 4, 5};
    vector<double> output{0, 0, 0, 0, 0};
    vector<double> expected{0, 0, 40, 0, 0};

    test("Test2", input,
         output,
         expected);
}

static void test3()
{
    // 输入数组中有两个0
    vector<double> input{1, 2, 0, 4, 0};
    vector<double> output{0, 0, 0, 0, 0};
    vector<double> expected{0, 0, 0, 0, 0};

    test("Test3", input,
         output,
         expected);
}

static void test4()
{
    // 输入数组中有正、负数
    vector<double> input{1, -2, 3, -4, 5};
    vector<double> output{0, 0, 0, 0, 0};
    vector<double> expected{120, -60, 40, -30, 24};

    test("Test4", input,
         output,
         expected);
}

static void test5()
{
    // 输入输入中只有两个数字
    vector<double> input{1, -2};
    vector<double> output{0, 0};
    vector<double> expected{-2, 1};

    test("Test5", input,
         output,
         expected);
}

int main(int argc, char *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}