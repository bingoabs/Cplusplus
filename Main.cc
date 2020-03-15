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
#include <map>
#include <utility>
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

std::pair<string, int> process(vector<string> &v)
{
    if(!v.empty())
    // return std::pair<string, int>(v.back(), v.back().size()); // before c++11
    //or
    //make_pair(v.back(), v.back().size());
        return {v.back(), v.back().size()};
    else 
        return std::pair<string, int>();
}
int main(int argc, char *argv[])
{
    vector<string> names = {"Joe", "Libby", "Qiu"};
    vector<int> nums = {100, 100, 101};
    vector<std::pair<string, int>> result;
    auto bn = names.begin();
    auto be = names.end();
    auto bnum = nums.begin();
    while(bn != be)
    {
        result.push_back({*bn, *bnum});
        bn++;
        bnum++;
    }
    for(auto e : result)
        cout << e.first << " " << e.second << endl;
    std::map<string, size_t> word_cout;
    auto map_it = word_cout.begin();
    // *map_id is a reference to pair<const string, size_t>;
    cout << map_it->first;
    cout << " " << map_it->second;
    //map_it->first = "new key"; // raise error, as the key is const
    ++map_it->second;
} 