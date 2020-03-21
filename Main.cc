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
    size_t max = 2;
    char *storage = new char[max];
    size_t curr = 0;
    string input;
    while(std::getline(cin, input))
    {
        for(auto e : input)
        {
            if (curr < max)
                storage[curr++] = e;
            else
            {
                cout << "extend the array" << endl;
                char *temp = storage;
                size_t oldMax = max;
                max *= 2;
                storage = new char[max];
                for(size_t a = 0; a < oldMax; a++)
                    storage[a] = temp[a];
                storage[curr++] = e;
            }
            
        }
    }
    for(size_t a = 0; a < curr; a++)
        cout << storage[a] << " ";
} 