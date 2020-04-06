#include <iostream>

using namespace std;

/**
 * @brief duplicate     查找数组中重复的元素
 * @param numbers       数组
 * @param length        数组长度
 * @param duplication   记录重复的数字
 * @return
 */
bool duplicate(int numbers[], int length, int* duplication)
{
    // 确保数组不为空
    if(numbers == nullptr || length <= 0)
        return false;
    // 确保数组中的元素都在0~n-1的范围内
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    
    // 遍历数组
    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            // 观察当前元素是否与以当前元素为索引的数组元素相同，如果相同，则为重复元素
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            // 交换numbers[i]和numbers[numbers[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

// ====================测试代码====================
/**
 * @brief contains  数组中是否包含该数字
 * @param array     数组
 * @param length    数组长度
 * @param number    待检测数字
 * @return
 */
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}
/**
 * @brief test              测试代码
 * @param testName          char*   测试名称
 * @param numbers           int []  测试的数组
 * @param lengthNumbers     int     数组的长度
 * @param expected          int []  期待重复的元素
 * @param expectedExpected  int     期待重复的元素的个数
 * @param validArgument     bool    是否重复
 */
void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    // 验证
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    // 判断结果
    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}
