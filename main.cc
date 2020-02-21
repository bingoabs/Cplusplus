#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a[10] = {};
    int beg = 0;
    for(int &e : a)
    {
        e = beg++;
    };
    for(int e : a)
    {
        cout << e << " ";
    };
    cout << endl;
}