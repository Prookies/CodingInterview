#include <iostream>

// 使用递归的方式求解
int Fibonacci_Solution1(int n)
{
    if(n == 1)
        return 1;
    else if(n <= 0)
        return 0;
    return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}

// 自下而上的解法，使用迭代求解
int Fibonacci_Solution2(int n)
{
    if(n == 1)
        return 1;
    else if(n == 0)
        return 0;

    int prev = 0;
    int cur = 1;
    int result = 0;
    for(int i=2; i<=n; i++)
    {

        result = cur + prev;
        prev = cur;
        cur = result;
    }

    return result;
}

// 给予矩阵乘法
struct Matrix2By2
{
    Matrix2By2(long long m00 = 0, long long m01 = 0,
               long long m10 = 0, long long m11 = 0)
        : m_00(m00), m_01(m01), m_10(m10), m_11(m11)
    {}

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1,
                          const Matrix2By2& matrix2)
{
    return Matrix2By2(
                matrix1.m_00*matrix2.m_00 + matrix1.m_01*matrix2.m_10,
                matrix1.m_00*matrix2.m_01 + matrix1.m_01*matrix2.m_11,
                matrix1.m_10*matrix2.m_00 + matrix1.m_11*matrix2.m_10,
                matrix1.m_10*matrix2.m_01 + matrix1.m_11*matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1,1,1,0);
    }
    else if(n%2 == 0)
    {
        matrix = MatrixPower(n/2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n%2 == 1)
    {
        matrix = MatrixPower((n-1)/2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1,1,1,0));
    }

    return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;

    Matrix2By2 PowerNMinus2 = MatrixPower(n-1);
    return PowerNMinus2.m_00;
}

// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
