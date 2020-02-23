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
    unsigned long u1 = 3, u2 = 7;
    cout << (u1 & u2) << endl;
    cout << (u1 | u2) << endl;
    cout << (u1 && u2) << endl;
    cout << (u1 || u2) << endl;
}