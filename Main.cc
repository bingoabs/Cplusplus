#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::list;
using std::stack;
// using namespace std::placeholders;
// we can directly use the names in this namespace!

int main(int argc, char *argv[]){
    vector<int> vec;
    vec = {1, 1, 1, 1, 1};
    list<int> lst;
    int i;
    while(cin >> i)
        lst.push_back(i);
    for(auto c : lst)
        cout << c << " " << endl;
    std::copy(lst.cbegin(), lst.cend(), vec.begin());
    for(auto c : vec)
        cout << c << endl;
    cout << "end" << endl;
}