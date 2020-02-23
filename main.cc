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
    vector<int> vint = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = vint.begin();
    cout << *iter++ << endl;
    cout << *iter << endl;
    cout << ++*iter << endl;
    cout << (*iter)++ << " " << *iter << endl;
    for(auto i : vint)
    {
        cout << i << " ";
    };
    cout << endl;
    for(auto iter = vint.begin(); iter != vint.end(); ++iter)
    {
        ++*iter; // fetch the value in vector and increase
    };
    for(auto i : vint)
    {
        cout << i << " ";
    };
    cout << endl;
}