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
    string input, last = "";
    int cnt = 1;
    while (cin >> input) {
        if (input == last){
            ++cnt;
        }
        else {
            cout << "input:" << " '" << last << "'" << " " << cnt << " times" << endl;
            last = input;
            cnt = 1;
        }
    }
}