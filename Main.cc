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
#include <memory>
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
using std::shared_ptr;
using std::unique_ptr;



int main(int argc, char *argv[])
{
    string a = "test";
    string b = "test";
    size_t len = a.size() + b.size();
    char *str = new char[len];
    size_t index = 0;
    for(auto e : a)
        str[index++] = e;
    for(auto e : b)
        str[index++] = e;
    cout << "index: " << index << endl;
    for(auto a = 0; a < len; a++)
        cout << str[a] << " ";
} 