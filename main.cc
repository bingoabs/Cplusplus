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
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int (*p)[4] = ia;
    p = &ia[2];

    for (int (*p)[4] = ia; p != ia + 3; ++p)
    {
        for(int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    };

    // for (auto p = begin(ia); p != end(ia); ++p)
    // {
    //     for (auto q = begin(*p); q != en(*p); ++q)
    //         cout << *q << ' ';
    //     cout << endl;
    // };
}