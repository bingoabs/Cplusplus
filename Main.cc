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
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //vec.reserve(10);
    // fill_n and copy requires the target array to 
    // have enough space to store the data
    fill_n(vec.begin(), 10, 0);
    for(auto a : vec)
        cout << a << " ";
    cout << "end" << endl;
}