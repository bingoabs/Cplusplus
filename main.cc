#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <iterator>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p0 = ia;
    int *p1 = &ia[2];
    int *p2 = &ia[3];
    p1 += p2 - p1;
    cout << *p1 << " " << "p1" << endl;

    for(auto a : ia)
    {
        cout << a << " ";
    };
    cout << endl;
    
    for(int *beg = ia; beg < ia + 10; ++beg)
    {
        *beg = 0;
    };
    for(auto a : ia)
    {
        cout << a << " ";
    };
    cout << endl;
}