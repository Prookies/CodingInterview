#include <iostream>
#include <limits>

using namespace std;

class CharStatistics
{
public:
    CharStatistics() : index(0)
    {
        for (int i = 0; i < 256; i++)
        {
            occurrence[i] = -1;
        }
    }

    void Insert(char ch)
    {
        if (occurrence[ch] == -1)
        {
            // 记录每个字符最先出现的位置
            occurrence[ch] = index;
        }
        else if (occurrence[ch] >= 0)
        {
            occurrence[ch] = -2;
        }
        index++;
    }

    char FirstAppearingOnce()
    {
        char ch = '\0';
        int SmallestIdx = INT_MAX;
        for (int i = 0; i < 256; i++)
        {
            if (occurrence[i] >= 0 && occurrence[i] < SmallestIdx)
            {
                SmallestIdx = occurrence[i];
                ch = i;
            }
        }

        return ch;
    }

private:
    int occurrence[256];
    int index;
};

// ====================测试代码====================
void Test(const char *testName, CharStatistics chars, char expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char *argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}
