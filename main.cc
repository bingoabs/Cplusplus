#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// using int_array = int[4]; new way to get an alias
// typedef int int_array[4]; old way to get an alias
int main()
{
    // int x[10]; int *p = x;
    // cout << sizeof(x)/sizeof(*x) << endl;
    // cout << sizeof(p)/sizeof(*p) << endl;
    int x = 10, y = 20;
    cout << (sizeof x + y) << endl;
    cout << (sizeof x < y) << endl;
}