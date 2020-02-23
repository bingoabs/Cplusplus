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
    const char *cp = "Hello World";
    // the cp can't change the value even without the 'const'
    int num;
    while(cin >> num)
    {
        if (num == 42)
        {
            cout << "Find 42, break;" << endl;
        } else 
        {
            cout << "Input next num;" << endl;
        }
    }
    // assign operator
    int i = get_value();
    while(i != 42)
    {
        // other codes
        i = get_value();
    }
    // elegant way to write
    int i;
    while(i = get_value())
    {
        // other codes
    };
}