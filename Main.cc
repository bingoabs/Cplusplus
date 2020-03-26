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

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&" << std::endl;}
    X& operator=(const X &rhs)
    {
        std::cout << "operator= (const X &rhs)" << endl;
        return *this;
    }
    ~X(){
        std::cout << "~X()" << endl;
    }
};

int main(int argc, char *argv[])
{
    X a, b;
    std::cout << "-----" << std::endl;
    a = X();
    std::cout << "-----" << std::endl;
    b = a;
    std::cout << "-----" << std::endl;
    auto c = &b;
    std::cout << "-----" << std::endl;
    X *d = new X;
    std::cout << "-----" << std::endl;
} 