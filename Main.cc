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
    private:
        int Age;
        string *Name;
    public:
        HasPtr(int age, string name):Age(age),Name(new string(name)){}
        HasPtr(const HasPtr&);
        HasPtr& operator=(const HasPtr&);
        ~HasPtr();
};

HasPtr::HasPtr(const HasPtr& rhs):
    Name(new string(*rhs.Name)), Age(rhs.Age){}

HasPtr::~HasPtr() { delete Name;}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.Name);
    delete Name;
    Name = newp;
    Age = rhs.Age;
    return *this;
}

int main(int argc, char *argv[])
{
    return 0;
} 