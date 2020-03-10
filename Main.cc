#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
// using namespace std::placeholders;
// we can directly use the names in this namespace!


int main(int argc, char *argv[]){
    vector<char> vchar = {'a', 'b', 'c', 'd'};
    string s(vchar.begin(), vchar.end());
    cout << s << endl;
}