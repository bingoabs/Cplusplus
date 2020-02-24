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
    const unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt;
    cin >> swt;
    switch (swt) {
        case ival:
            cout << "ival" << endl;
            break;
        case jval:
            cout << "jval" << endl;
            break;
        case kval:
            cout << "kval" << endl;
            break;
        default:
            cout << "default" << endl;
            break;
    }
    cout << "end" << endl;
}