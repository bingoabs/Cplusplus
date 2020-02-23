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
    // vector<int> ivec = {1, 2, 3, 4, 5};
    // vector<int>::size_type cnt = ivec.size();
    // for(vector<int>::size_type ix = 0;
    //     ix != ivec.size(); ix++, cnt--)
    //     ivec[ix] = cnt;
    // for(auto x : ivec)
    //     cout << x << " ";
    // cout << endl;
    int x = 10, y = 15;
    int input;
    cin >> input;
    cout << ((input > 10) ? (++x, ++y) : --x, --y) << endl;
    cout << x << " " << y << endl;
    cout << ++y << endl;
}