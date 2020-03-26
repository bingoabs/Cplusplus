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

// Value Type class
// class HasPtr{
//     private:
//         int Age;
//         string *Name;
//     public:
//         HasPtr(int age, string name):Age(age),Name(new string(name)){}
//         HasPtr(const HasPtr&);
//         HasPtr& operator=(const HasPtr&);
//         ~HasPtr();
// };

// HasPtr::HasPtr(const HasPtr& rhs):
//     Name(new string(*rhs.Name)), Age(rhs.Age){}

// HasPtr::~HasPtr() { delete Name;}

// HasPtr& HasPtr::operator=(const HasPtr& rhs)
// {
//     auto newp = new string(*rhs.Name);
//     delete Name;
//     Name = newp;
//     Age = rhs.Age;
//     return *this;
// }

// Shared Type class

class HasPtr
{
    public:
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0), use(new std::size_t(1)){}
        HasPtr(const HasPtr &p):
            ps(p.ps), i(p.i), use(p.use){++*use;}
        HasPtr& operator=(const HasPtr&);
        ~HasPtr();
    private:
        string *ps;
        int i;
        size_t *use; // used to record the number of references
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

int main(int argc, char *argv[])
{
    return 0;
} 