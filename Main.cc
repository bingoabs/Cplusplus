#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
#include <iterator> // for the istream_iterator
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;
using std::list;
using std::stack;

int main(int argc, char *argv[]){
    std::istream_iterator<int> in(cin);
    std::istream_iterator<int> in_eof;
    vector<int> nums;
    while(in != in_eof)
        nums.push_back(*in++);
    std::stable_sort(nums.begin(), nums.end(), [](int a, int b) { return a > b;});
    for(int a : nums)
        cout << a << " ";
    cout << endl;
    list<int> u_nums;
    std::unique_copy(nums.begin(), nums.end(), u_nums.begin());
    cout << u_nums.size() << endl;
    for(int a : u_nums)
        cout << a << " ";
    cout << endl;
} 