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
    int ia[3][4];
    int (*p)[4] = ia;
    p = &ia[2];

    for (auto p = ia; p != ia + 3; ++p)
    {
        for(auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    };

    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != en(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    };
}