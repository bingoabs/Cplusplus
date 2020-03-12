#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
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
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
    const char *a = argv[1];
    const char *b = argv[2];
    vector<const char*> va = {a};
    vector<const char*> vb = {b};
    cout << std::equal(va.begin(), va.end(), vb.begin()) << endl;
    string s = argv[1];
    string d = argv[2];
    vector<string> vs = {s};
    vector<string> vd = {d};
    cout << std::equal(vs.begin(), vs.end(), vd.begin()) << endl;
}