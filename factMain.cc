#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;

void f(){ cout << "f()" << endl;}
void f(int a) {cout << "f(int a)" << endl;}
void f(int a, int b) {cout << "f(int, int)" << endl;}
void f(double a, double b = 3.14) {cout << "f(double, double = 3.14)" << endl;}

int main(){
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}