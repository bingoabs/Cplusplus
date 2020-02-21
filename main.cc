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
    unsigned cnt = 42;
    constexpr unsigned sz = 42;
    //const unsigned sz = 100;
    int arr[10];
    int *parr[sz]; // right, as the `sz` is the constexpr
    //string bad[cnt];  error, the cnt not const or constexpr
    //string strs[get_size()]; error if the get_size() is not a constexpr

    const unsigned sz = 3;
    int ial[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2}; // equals to a3[] = {0, 1, 2, 0, 0};
    string a4[3] = {"hi", "bye"}; // equals to a4[] = {"hi", "bye", ""};

    char a1[] = {'c', '+', '+'};
    char a2[] = {'c', '+', '+', '\0'};
    char a3[] = "c++"; // equals to a3[] = {'c', '+', '+', '\0'};
    //const char a4[6] = "Daniel";
    // error, as the char array need one more space to store the "Zero"
}