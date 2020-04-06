#include <iostream>

using namespace std;

void PrintMatrixInCricle(int **numbers, int cols, int rows, int start);

void PrintMatrixClockwisely(int **numbers, int cols, int rows)
{
    if (numbers == nullptr || cols == 0 || rows == 0)
    {
        return;
    }

    int start = 0;
    while (2 * start < cols && 2 * start < rows)
    {
        PrintMatrixInCricle(numbers, cols, rows, start);
        start++;
    }
}

void PrintMatrixInCricle(int **numbers, int cols, int rows, int start)
{
    cols -= start;
    rows -= start;

    // 打印一行
    for (int i = start; i < cols; i++)
    {
        cout << numbers[start][i] << " ";
    }

    // 如果终止列大于起始列，则打印一列
    if (rows - 1 > start)
    {
        for (int i = start + 1; i < rows; i++)
        {
            cout << numbers[i][cols - 1] << " ";
        }

        if (cols - 1 > start)
        {
            for (int i = cols - 2; i >= start; i--)
            {
                cout << numbers[rows - 1][i] << " ";
            }

            if (rows - start > 2)
            {
                for (int i = rows - 2; i > start; i--)
                {
                    cout << numbers[i][start] << " ";
                }
            }
        }
    }
}

// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if (columns < 1 || rows < 1)
        return;

    int **numbers = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for (int i = 0; i < rows; ++i)
        delete[](int *) numbers[i];

    delete[] numbers;
}

int main(int argc, char *argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}