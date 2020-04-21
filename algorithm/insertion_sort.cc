#include <iterator>
#include <iostream>
using std::cout;
using std::endl;
using std::end;
using std::begin;

void insertion_sort(int* begin, int* end)
{
    if ((begin == end) || ((begin + 1) == end))
        return;
    int *last_ptr;
    for(int* cur_ptr = begin + 1; cur_ptr != end; cur_ptr++)
    {
        int current = *cur_ptr;
        last_ptr = cur_ptr - 1;
        while((last_ptr >= begin) && (*last_ptr < current)) 
        // change to ">" can be ascend or descend order
        {
            *(last_ptr + 1) = *last_ptr;
            last_ptr -= 1;
        }
        *(last_ptr + 1) = current;
    }
}

void check(int* beg, int* end, int t)
{
    int* s;
    for(s = beg; s!= end; s++)
        if(*s == t) break;
    if (*s == t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

template <int Size>
void sum(int (&arr1)[Size], int (&arr2)[Size])
{
    int arr3[Size+1];
    for(int index = 0, add = 0; index < Size; ++index)
    {
        int temp = arr1[index] + arr2[index] + add;
        if(temp == 0)
        {
            arr3[index] = 0;
            add = 0;
        }
        if(temp == 1)
        {
            arr3[index] = 1;
            add = 0;
        }
        if (temp == 2)
        {
            arr3[index] = 0;
            add = 1;
        }
        if (temp == 3){
            arr3[index] = 1;
            add = 1;
        }
    }
    for(int i : arr3)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // int arr[] = {10, 2, 3, 12, 3, 1};
    // insertion_sort(begin(arr), end(arr));
    // for(auto e : arr)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // int arr[] = {10, 2, 3, 12, 3, 1};
    // check(begin(arr), end(arr), 10);
    // check(begin(arr), end(arr), 15);
    // return 0;

    int arr1[5] = {1, 0, 0, 1, 1};
    int arr2[5] = {0, 1, 1, 1, 1};
    sum(arr1, arr2);
}