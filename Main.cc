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
    unique_ptr<int[]> up(new int[10]);
    for(size_t i = 0; i != 10; ++i)
        up[i] = i;
    up.release(); // using delete [] destroy the bottom ptr
    shared_ptr<int> sp(new int[10], [](int *p){delete [] p;});
    // shared_ptr doesn't directly support the `new array`
    // instead we need define the `self-define deleter`
    for(size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i;
    sp.reset();
} 