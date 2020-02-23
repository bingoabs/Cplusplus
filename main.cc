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
    int i; double d;
    d = i = 3.5;
    cout << d << " " << i << endl;
    i = d = 3.5;
    cout << d << " " << i << endl;
    cout << endl;
    double dval; int ival; int *pi;
    dval = ival = 0;
    pi = 0;

    auto pbeg = v.begin();
    while(pbeg != v.end() && *pbeg >= 0)
    {
        cout << *pbeg++ << endl;
    };
}