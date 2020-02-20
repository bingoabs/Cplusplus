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
    vector<int> sorted_nums = {0, 10, 20, 20, 30, 40, 50, 60, 70, 80, 90};
    int sought = 10;
    auto beg = sorted_nums.begin(), end = sorted_nums.end();
    auto mid = sorted_nums.begin() + (end - beg)/2;
    while(mid != end && *mid != sought)
    {
        if(sought < *mid)
        {
            end = mid;
        } else {
            beg = mid + 1;
        };
        mid = beg + (end - beg)/2;
        cout << "one loop" << endl;
    }
}