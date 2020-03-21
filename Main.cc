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
    int *pia = new int[10];
    int *pia2 = new int[10]();
    string *psa = new string[10];
    string *psa2 = new string[10]();
    int *pia3 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *a = new int(100);
    delete a;
    delete [] pia;
} 