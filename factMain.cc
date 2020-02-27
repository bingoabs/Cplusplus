#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;

// same function using different define
string (&returnStrArray(vector<string> input))[2];
auto returnStrArray1(vector<string> input) -> string (&)[2];
string strArrayRaw[2] = {"first", "second"};
string (&strArray)[2] = strArrayRaw;
decltype(strArrayRaw) &returnStrArray2(vector<string> input);
typedef string strArrayType[2]; // using strArrayType = string[2];
strArrayType &returnStrArray3(vector<string> input);

typedef int (*arrT)[1];

int main(){
    int arr[1] = {100};
    arrT list = {&arr};
    decltype(list) b = &arr;
}