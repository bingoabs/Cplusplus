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
        while((last_ptr >= begin) && (*last_ptr > current))
        {
            *(last_ptr + 1) = *last_ptr;
            last_ptr -= 1;
        }
        *(last_ptr + 1) = current;
    }
}

int main()
{
    int arr[] = {10, 2, 3, 12, 3, 1};
    insertion_sort(begin(arr), end(arr));
    for(auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}