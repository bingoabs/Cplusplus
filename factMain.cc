#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;

typedef int(*first)(int a, int b);

int main(){
    vector<first> b;
    vector<int(*)(int, int)> a;
    cout << "end" << endl;
}