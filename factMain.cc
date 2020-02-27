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

int main(){
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;
    return 0;
}