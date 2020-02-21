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
    // the size of array is 3, every element is a array who has 4 element.
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // or
    // int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr[10][20][30] = {0};// set all elements to 0!

    ia[2][3] = arr[0][0][0];
    int (&row)[4] = ia[1];
    // bind the `row` to a array which contains 4 int elements
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    for(size_t i = 0; i != rowCnt; ++i)
    {
        for(size_t j = 0; j != colCnt; ++j)
        {
            ia[i][j] = i * colCnt + j;
        }
    }
}