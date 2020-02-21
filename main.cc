#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = arr;// head ptr of arr
    ++p;
    int *e = &arr[10]; // end + 1 ptr of arr
    for(int *b = arr; b != e; ++b)
    {
        cout << *b << endl;
    };
    cout << "next one" << endl;
    for(int *b = arr; b != &arr[9]; ++b)
    {
        cout << *b << endl;
    }
}