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
#include <istream>
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
using std::ifstream;

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
    public:
        int i;
        string *ps;
        HasPtr():ps(new string()), i(0){}
        HasPtr(int n):ps(new string()), i(n){}
        bool operator<(const HasPtr&);
        ~HasPtr(){
            delete ps;
        }
};
bool HasPtr::operator<(const HasPtr &rhs){
    return rhs.i > i;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "into swap" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char *argv[])
{
    vector<HasPtr> a{HasPtr(10), HasPtr(2), HasPtr(11)};
    a.push_back(HasPtr(5));
    std::sort(a.begin(), a.end());
    return 0;
} 