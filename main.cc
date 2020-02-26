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

void print(const char *cp)
{
    if (cp)
        while(*cp)
            cout << *cp++ << endl;
}

void print(const int *beg, const int *end)
{
    while(beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        cout << ia[i] << endl;
    }
}

void print(int (&arr)[10])
// Only the array with ten element can work!
{
    for(auto elem : arr)
    {
        cout << elem << endl;
    }
}

void print(string arr[10])
// for `array` param, the `10` just for showing, not check the element number
{
    size_t size = 5;
    for(size_t index = 0; index < size; ++index)
    {
        cout << arr[index] << endl;
    }
    // for (auto elem : arr)
    // {
    //     cout << elem << endl;
    // }
    // the `arr` looks like a array self,
    // but actually it is a ptr to array,
    // the first element in array!
}

int main()
{
    //int a[5] = {0, 1, 2, 3, 4};
    //raised error, because the a[5] doesn't match the `in (&arr)[10]`
    int intArray[10] = {0, 1, 2, 3, 4};
    print(intArray);

    string strArray[6] = {"first", "second", "third", "four", "five", "six"};
    print(strArray);
    // the definition set the 10, but only 6 element array can work!
}