#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool> &visited);
bool check(int threshold, int rows, int cols, int row, int col, vector<bool> &visited);
int getDigitSum(int number);


int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    int len = rows*cols;
    // 每个格子的访问状态
    vector<bool> visited(len, false);

    return movingCountCore(threshold, rows, cols, 0, 0, visited);
}

// 注意这里vector需要使用引用
int movingCountCore(int threshold, int rows, int cols, int row, int col,
                    vector<bool> &visited)
{
    if(check(threshold, rows, cols, row, col, visited))
    {
        visited[row*cols + col] = true;
        return 1 + movingCountCore(threshold, rows, cols, row-1, col, visited)
                + movingCountCore(threshold, rows, cols, row+1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col-1, visited)
                + movingCountCore(threshold, rows, cols, row, col+1, visited);
    }

    return 0;
}

bool check(int threshold, int rows, int cols, int row, int col, vector<bool> &visited)
{
    if(row >= 0 && row < rows && col >=0 && col < cols
       && getDigitSum(row) + getDigitSum(col) <= threshold
       && !visited[row*cols + col])
        return true;

    return false;
}

int getDigitSum(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number%10;
        number/=10;
    }

    return sum;
}

// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
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

    return 0;
}
