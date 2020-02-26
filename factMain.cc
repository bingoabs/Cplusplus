#include "Chapter6.h"
#include <iostream>
#include <initializer_list>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;

void error_msg(initializer_list<string> li)
{
    for(auto beg = li.begin(); beg != li.end(); ++beg){
        cout << *beg << " ";
    }
    cout << endl;
}
int reduce(initializer_list<int> li){
    int result = 0;
    for(auto beg = li.begin(); beg != li.end(); ++beg)
    {
        result += *beg;
    }
    return result;
}

int main(){
    initializer_list<string> ls = {"first", "second", "third", "four", "five"};
    initializer_list<int> li = {1, 2, 3, 4, 5, 6, 7};
    cout << reduce(li) << endl;
    error_msg(ls);
    string some_object;
    error_msg({"functionX", "okay", some_object});
    return 0;
}