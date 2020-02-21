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
    string nums[] = {"one", "two", "three"};
    string *p = &nums[0];

    string *p2 = nums; // equals to p2 = &nums[0];

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia); // equals to int *ia2 = &ia[0];

    decltype(ia) ia3 = {1, 1, 1, 1, 1, 1, 1};
    // equals to int ia3[] = {...};
    ia3[4] = 10;
}