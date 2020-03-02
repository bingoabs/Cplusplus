#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;


// Define the function member for Struct/Class
// The `const` before `{` is used for `this`
// double Sales_data::avg_price() const {
//     if (units_sold)
//         return revenue/units_sold;
//     else
//     {
//         return 0;
//     }
// }

struct People {
    string name = "name";
    string address;
    string get_name() const;
    string get_address() const;
};// Notice must have the semicolon !!!

string People::get_name() const {
    return name;
}
string People::get_address() const {
    return address;
}

int main(){
    People first;
    cout << first.get_name() << endl;
}