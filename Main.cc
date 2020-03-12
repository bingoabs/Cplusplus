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
    const char *a = "test";
    const char *b = "test1";
    for(int index = 0; *a != '\0'; ++index, ++a)
        cout << index << " " << *a << endl;
}