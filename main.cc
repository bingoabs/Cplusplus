#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// using int_array = int[4]; new way to get an alias
// typedef int int_array[4]; old way to get an alias
int main()
{
    int ival = 42;
    double dval = 3.14;
    ival % 12;
    //ival % dval; error
    vector<string> text = {"test", "test"};
    for(const auto &s : text){
        cout << s;
        if (s.empty() || s[s.size() - 1] == '.')
            cout << endl;
        else
        {
            cout << " ";
        }
    };
    cout << endl;
    const char *cp = "Hello World";
    // generate a char array?
}