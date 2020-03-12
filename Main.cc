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
#include <forward_list>
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
using std::forward_list;

int main(int argc, char *argv[]){
    // list<int> nums = {11, 11, 11};
    // list<int> ln = {1, 2, 3, 4, 5};
    // ln.splice(ln.begin(), nums);
    // for(auto n : ln)
    //     cout << n << endl;

    forward_list<int> nums = {11, 12, 13};
    forward_list<int> fn = {7, 8, 9, 10};
    forward_list<int>::iterator begin = nums.begin();
    begin++;
    begin++;
    begin++;
    fn.splice_after(fn.before_begin(), nums, nums.begin(), begin);
    for(auto n : fn)
        cout << n << endl;
} 