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
    std::istream_iterator<int> in(cin);
    std::istream_iterator<int> in_eof;
    // It looks like one istream_iterator can't reuse
    // vector<int> vn(in, in_eof);
    // for(auto v : vn)
    //     cout << v << " ";
    // cout << endl;
    vector<int> vn2(10, 1);
    auto end = std::copy(in, in_eof, vn2.begin());
    
    for(auto v : vn2)
        cout << v << " ";
    cout << endl;
    cout << *end << endl;
    cout << (vn2.begin() - end) << endl;
} 