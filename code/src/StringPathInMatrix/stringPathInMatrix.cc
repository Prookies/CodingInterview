#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool hasPathCore(const char* matrix, int row, int col, int rows, int cols, const char* str, int& pathLength, vector<bool> visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    int len = rows*cols;

    //    bool *visited = new bool[len];
    //    for(int i=0; i < len; i++)
    //    {
    //        visited[i] = 0;
    //    }
    // 需不需要用智能指针进行管理。由于其是出错，所以使用智能指针容易出错，可以使用vector
    vector<bool> visited(len, false);

    int pathLength = 0;
    // 对整个矩形搜索
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            // 判断当前字符是否与字符串第一个字符匹配，如果匹配，对四周进行搜索
            if(hasPathCore(matrix, row, col, rows, cols, str, pathLength, visited))
            {
                // 如果使用指针，在这里也应该加上一条delete语句
                return true;
            }
        }
    }

    // delete [] visited;
    return false;
}

//bool hasPathCore(const char* matrix, int row, int col, int rows, int cols, const char* str)
//{
//    int len = rows*cols;
//    stack<pair<int,int>> s;

//    bool *visited = new bool[len];
//    for(int i=0; i < len; i++)
//    {
//        visited[i] = 0;
//    }


//    int idx = 0;
//    while(str[idx] != '\0')
//    {
//        cout << "row:" << row << ", col:" << col << endl;
//        cout << str[idx] << ":" << matrix[row*cols + col] << endl;
//        if(str[idx] != matrix[row*cols + col] && s.empty())
//            return false;

//        if(str[idx] == matrix[row*cols + col])
//        {

//            visited[row*cols + col] = 1;
//            // 将周围元素纳入到观察对象
//            if((row-1) >= 0 && !visited[(row-1)*cols + col])
//            {
//                s.push(make_pair(row-1,col));
//            }
//            if((row+1) < rows && !visited[(row+1)*cols + col])
//            {
//                s.push(make_pair(row+1,col));
//            }
//            if((col-1) >= 0 && !visited[row*cols + col - 1])
//            {
//                s.push(make_pair(row,col-1));
//            }
//            if((col+1) < cols && !visited[row*cols + col + 1])
//            {
//                s.push(make_pair(row,col+1));
//            }

//            idx++;
//        }

//        if(!s.empty())
//        {
//            row = s.top().first;
//            col = s.top().first;
//            s.pop();
//        }


//    }

//    delete [] visited;
//    return true;
//}

bool hasPathCore(const char* matrix, int row, int col, int rows, int cols, const char* str, int& pathLength, vector<bool> visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
       && matrix[row*cols + col] == str[pathLength]
       && !visited[row*cols + col])
    {
        ++pathLength;
        visited[row*cols + col] = true;

        hasPath = hasPathCore(matrix, row, col-1, rows, cols, str, pathLength, visited)
                  || hasPathCore(matrix, row-1, col, rows, cols, str, pathLength, visited)
                  || hasPathCore(matrix, row, col+1, rows, cols, str, pathLength, visited)
                  || hasPathCore(matrix, row+1, col, rows, cols, str, pathLength, visited);

        // 进行回溯
        if(!hasPath)
        {
            --pathLength;
            visited[row*cols + col] = false;
        }
    }

    return hasPath;

}

// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}
