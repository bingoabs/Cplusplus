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
    vector<int> a, b;
    a = {1, 2, 3, 4, 5, 6, 7, 8};
    // b = {1, 2, 3, 4, 5, 6};
    b = {1, 2, 3, 4, 5, 5};
    bool isPrefix = true;
    for(auto ab = a.begin(), bb = b.begin(); ab != a.end() && bb != b.end(); ++ab, ++bb){
        if(*ab != *bb)
            isPrefix = false;
    }
    cout << isPrefix << endl;
}