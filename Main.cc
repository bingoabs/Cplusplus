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

int main(int argc, char *argv[]){
    std::map<vector<int>::iterator, int> wordsLineNum;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5};
    wordsLineNum = {
        {a.begin(), 10},
        {b.begin(), 10}
    };
} 