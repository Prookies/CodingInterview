#include <iostream>
#include <exception>

using namespace std;

int MinInOrder(int* numbers, int index1, int index2);

// 其中有一个问题是如果客户没有按规定输入旋转的数组怎么办
int Min(int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        throw "Invalid parameters";

    int idx1 = 0;           // 指向开头
    int idx2 = length - 1;  // 指向结尾
    while(idx1 < idx2-1)
    {
        int mid = ((idx2 - idx1)>>1) + idx1;
        cout << mid << endl;
        if(numbers[idx1] > numbers[idx2])
        {
            if(numbers[mid] >= numbers[idx1])
                idx1 = mid;
            else if(numbers[mid] <= numbers[idx2])
                idx2 = mid;
        }
        else if(numbers[idx1] == numbers[idx2])
        {
            if(numbers[mid] == numbers[idx1])
            {
                int idx = mid;
                int flag = 0;
                // 向左搜索断点
                while(idx1 < idx)
                {
                    if(numbers[idx1] == numbers[idx])
                    {
                        idx--;
                    }
                    else{
                        if(numbers[idx] > numbers[idx1])
                            idx1 = idx;
                        else if(numbers[idx] < numbers[idx2])
                            idx2 = idx;
                        else
                            throw "error ==";
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    idx = mid;
                    // 向右搜索断点
                    while(idx2 > idx)
                    {
                        if(numbers[idx2] == numbers[idx])
                        {
                            idx++;
                        }
                        else{
                            if(numbers[idx] > numbers[idx1])
                                idx1 = idx;
                            else if(numbers[idx] < numbers[idx2])
                                idx2 = idx;
                            else
                                throw "error ==";
                            break;
                        }
                    }
                }

            }
            else{

                if(numbers[mid] > numbers[idx1])
                    idx1 = mid;
                else if(numbers[mid] < numbers[idx2])
                    idx2 = mid;
            }
        }
        else{
            idx2 = idx1;
            break;
        }

    }

    return numbers[idx2];
}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 3, 1, 1, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 1);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}
