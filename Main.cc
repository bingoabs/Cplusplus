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
    size_t n = 100;
    // string *const p = new string[n];
    // string s;
    // string *q = p;
    // while(cin >> s && q != p + n)
    //     *q++ = s;
    // const size_t size = q - p;
    // delete [] p;
    allocator<string> alloc;
    // auto const p = alloc.allocate(n);
    string *const p = alloc.allocate(n); //string const *p = alloc.allocate(n); is error expression
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    cout << *p << endl;
    cout << *q << endl;
    while(q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
} 