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
using std::allocator;


int main(int argc, char *argv[])
{
    vector<int> inputs{1, 2, 3, 4, 5, 6};
    allocator<int> alloc;
    auto p = alloc.allocate(inputs.size() * 2);
    auto q = std::uninitialized_copy(inputs.begin(), inputs.end(), p);
    std::uninitialized_fill_n(q, inputs.size(), 42);
} 