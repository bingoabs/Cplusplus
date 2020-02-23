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
    // int j = 10, i = 99;
    // double slope = static_cast<double>(j) / i;

    // double d = 100.0;
    // void* p = &d;
    // double *dp = static_cast<double*>(p);

    // const char *pc;
    // char *p = const_cast<char*>(pc);

    // int *ip;
    // char *pc = reinterpret_cast<char*>(ip);
    // the pc point to a `int`, but we can change the point type to `char`
    // treat `pc` as a real char ptr may raise error, like:
    // string str(pc); would raise error in runtime

    double d = 1.2343;
    int i = 123;
    i*=static_cast<int>(d);
    cout << i << endl;
}