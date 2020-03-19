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

std::shared_ptr<vector<int>> recv(std::shared_ptr<vector<int>> p)
{
    int input;
    while(cin >> input)
        p->push_back(input);
    return p;
}
 
void print(std::shared_ptr<vector<int>> p)
{
    vector<int> a = *p;
    for(int e : a)
        cout << e << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    std::shared_ptr<vector<int>> a = std::make_shared<vector<int>>();
    a = recv(a);
    print(a);
} 