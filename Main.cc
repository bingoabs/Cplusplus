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

void process(shared_ptr<int> p)
{
    cout << "p use_count: " << p.use_count() << endl;
}

int main(int argc, char *argv[])
{
    shared_ptr<int> p(new int(31));
    process(shared_ptr<int>(p.get()));
    cout << "end count: " << p.use_count() << endl;
} 