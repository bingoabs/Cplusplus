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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto &n : nums)
    {
        n = n * 2;
    };
    for(auto n : nums)
    {
        cout << n << endl;
    };
}