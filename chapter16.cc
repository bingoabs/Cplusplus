#include <iostream>
#include <vector>
#include <iterator>
using std::begin;
using std::end;
using std::vector;
using std::endl;
using std::cout;

// template <typename T> int compare(const T &v1, const T &v2)
// {
//     if (v1 > v2) return -1;
//     if (v2 > v1) return 1;
//     return 0;
// }

// struct Example {
//     public:
//         Example(int num):price(num){}
//         bool operator>(const Example&) const;
//         // withou the "const", the "rhs.get_price" can't run
//         // due to the rhs is a const Example,
//         // it only can invoke the const members.
//         // but the regular Example can call both const and non-const member
//         int get_price() const {return price;}
//     private:
//         int price; 
// };

// bool Example::operator>(const Example &rhs) const
// {
//     return (this->get_price() > rhs.get_price());
// }

// int main()
// {
//     cout << compare<Example>(Example(100), Example(10)) << endl;
//     cout << compare<Example>(Example(10), Example(100)) << endl;
//     return 0;
// }

// template <typename inputiterator, typename input>
// inputiterator find(inputiterator beg, inputiterator end, input val)
// {
//     inputiterator start;
//     for(start = beg; start != end; start++)
//         if (*start == val) break;
//     if (*start == val)
//         return start;
//     return end;
// }

// int main()
// {
//     vector<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9};
//     cout << (find(l.begin(), l.end(), 100) == l.end()) << endl;
//     cout << *find(l.begin(), l.end(), 2) << endl;
//     return 0;
// }

// template <int Size> void print(int (&arr)[Size])
// {
//     for(int* beg = begin(arr); beg != end(arr); beg++)
//         cout << *beg << endl;
// }

// int main()
// {
//     int a[] = {1, 2, 3, 4, 5, 6};
//     print(a);
// }

template <int Size> constexpr int GetSize(int (&arr)[Size]){
    return Size;
};

int main()
{
    int arr[] = {100, 10, 1};
    cout << GetSize(arr) << endl;
}