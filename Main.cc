#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::list;
// using namespace std::placeholders;
// we can directly use the names in this namespace!

int main(int argc, char *argv[]){
    int a[] = {1, 2, 3, 4, 5};
    vector<int> vec(std::begin(a), std::end(a));
    list<int> li(std::begin(a), std::end(a));
    vector<int>::iterator iter = vec.begin();
    while(iter != vec.end())
    {
        if(!(*iter%2))
            iter = vec.erase(iter);
        else
        {
            iter++;
        }
    }
    list<int>::iterator liter = li.begin();
    while(liter != li.end())
    {
        if(*liter%2)
            liter = li.erase(liter);
        else
        {
            liter++;
        }
        
    }
    for(auto a : vec)
        cout << a << " ";
    cout << endl;
    for(auto b : li)
        cout << b << " ";
    cout << endl;
}