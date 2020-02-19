#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto i : v)
    {
        i = i + 1;
    };
    for(auto i : v)
    {
        cout << i << endl;
    };
    cout << "-----------------" << endl;
    for(auto &i : v)
    {
        i *= i;
    };
    for(auto i : v)
    {
        cout << i << endl;
    };
    cout << "------------------" << endl;
}