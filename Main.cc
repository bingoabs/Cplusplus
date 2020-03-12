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

int main(int argc, char *argv[]){
    string raw = "this is the test";
    char o = 'i';
    char n = 'I';
    string r;
    std::replace_copy_if(raw.begin(), raw.end(), std::back_inserter(r), [](char a){return a == 't';}, 'T');
    for(char a : r)
        cout << a << endl;
} 