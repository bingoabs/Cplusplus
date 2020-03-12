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
    std::ifstream f("fact.cc");
    std::istream_iterator<string> in(f);
    std::istream_iterator<string> in_eof;
    while(in != in_eof)
        cout << *in++ << endl;
    cout << endl;
} 