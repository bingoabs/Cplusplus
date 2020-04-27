#include <vector>
#include <iostream>

using namespace std;

/*
A = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
B = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
*/
// it is impossible to return a nested array
// unless 1. static, 2. dynamic alloc 3. only one layer
void n3(int** a, int **b)
{
    int c[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int acc = 0;
            cout << "here" << endl;
            for(int k = 0; k < 3; k++)
            {
                cout << (*(*(a + i) + k)) << endl;
                acc += (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
            *(*(c + i) + j) = acc;
        }
    }
    cout << "end" << endl;
    for(auto &a : c)
    {
        for(auto i : a)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    // return c;
    // must not return a pointer to the local variable!
}
int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    n3((int **)a, (int **)b);
}

