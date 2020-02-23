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
    string s1 = "a string", *p = &s1;
    auto n = s1.size(); // directly run the `size` member
    n = (*p).size(); // run `p` `size` member
    n = p->size(); // equals to last one
    // (ptr->name) == ((*ptr).name);
}