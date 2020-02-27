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

int plus(int a, int b) { return a + b;}
int sub(int a, int b){ return a - b;}
int del(int a, int b){return a/b;}
int mul(int a, int b){return a * b;}

int main(){
    vector<first> b;
    vector<int(*)(int, int)> a;
    a.push_back(plus);
    a.push_back(sub);
    cout << a[0](10, 20) << endl;
    cout << a[1](100, 50) << endl;
    cout << "end" << endl;
}