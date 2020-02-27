#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;

void error_msg(initializer_list<string> li)
{
    for(auto beg = li.begin(); beg != li.end(); ++beg){
        cout << *beg << " ";
    }
    cout << endl;
}
int reduce(initializer_list<int> li){
    int result = 0;
    for(auto beg = li.begin(); beg != li.end(); ++beg)
    {
        result += *beg;
    }
    return result;
}

string make_plural(size_t ctr, const string &word,
                                const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

// the params and the return type is the reference to `const string`
const string &shorterString(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}
// it is a invalid function
// `return local variable` is fine,
// but `return the reference to the local variable` can't work
// const string &manip()
// {
//     string ret;
//     if(!ret.empty())
//         return ret; // return a reference to local variable
//     else 
//         return "Empty"; // return a local variable
// }

// if the return type is reference,
// we can put the result of function in the left 
char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

vector<string> process()
{
    // ...
    // expected and actual both are the string object
    string expected = "expected", actual = "actual";
    if (expected.empty())
        return {};
    else if (expected == actual)
        return {"functionX", "okay"};
    else
        return {"functionX", expected, actual};
}

int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}

int &get(int *array, int index) { return array[index];}// equals to *(array + index)

int list(vector<int> ivec, vector<int>::size_type size)
{
    if (size < ivec.size())
    {   cout << ivec[size] << endl;
        return list(ivec, size + 1);
    }
    else 
        return 0;
}

int main(){
    // int ia[10]; // undefine, but still can get the reference!
    // for(int i = 0; i != 10; ++i)
    // {
    //     cout << get(ia, i) << endl;
    //     get(ia, i) = i;
    //     cout << get(ia, i) << endl;
    // }
    // cout << ia << endl;
    // cout << "here" << endl;
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list(ivec, 0);
}