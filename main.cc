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

int fact(int val){
    int ret = 1;
    while (val > 1){
        ret *= val--;
    }
    cout << "ret: " << ret << endl;
    return ret;
}

int main()
{
    int input;
    cin >> input;
    // when the input == 100, the result is wrong
    // due to the value too large to save in int!
    cout << "input: " << input << endl;
    int j = fact(input);
    cout << "input: " << input << "; result: " << j << endl;
}