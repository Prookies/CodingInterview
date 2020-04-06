#include <iostream>

using namespace std;

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    const char* str3 = "hello world";
    const char* str4 = "hello world";

    cout << (void*)str1 << endl
         << (void*)str2 << endl
         << (void*)str3 << endl
         << (void*)str4 << endl;
}
