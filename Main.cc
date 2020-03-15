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
#include <set>
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
using std::map;
using std::set;
using std::multiset;

int main(int argc, char *argv[])
{
    multiset<string> c = {"a", "b", "c"};
    vector<string> v = {"d", "e", "f"};
    // std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    // std::copy(v.begin(), v.end(), std::back_inserter(c)); // only this one failed
    // std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    std::copy(c.begin(), c.end(), std::back_inserter(v));
    multiset<string>::iterator cb = c.begin();
    while(cb != c.end())
    {
        cout << *cb << " ";
        cb++;
    }
    cout << endl;
    for(auto a : v)
        cout << a << " ";
    cout << endl;
    set<int> iset = {0, 1, 2, 3, 4, 5, 6};
    iset.find(1); // return a set<int>::iterator reference to the key == 1 element
    iset.find(11); // return a set<int>::iterator reference to the one after tail
    iset.count(1); // return 1;
    iset.count(11); // return 0;
} 