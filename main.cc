#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
// using int_array = int[4]; new way to get an alias
// typedef int int_array[4]; old way to get an alias
int main()
{
    try {
        string a;
        cin >> a;
        if (a != "test")
            throw runtime_error("test");
        cout << "no error" << endl;
    } catch (runtime_error err){
        cout << err.what()
            << endl
            << "this is the error message" << endl;
    }
}