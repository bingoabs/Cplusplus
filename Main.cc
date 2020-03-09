#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
// using namespace std::placeholders;
// we can directly use the names in this namespace!

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main(int argc, char *argv[]){
    //string words[3] = {"a", "b", "c"};// built-in array has not the iterator!
    vector<string> words = {"a", "ber", "c", "d"}; 
    auto wc = std::find_if(words.begin(), words.end(), bind(check_size, _1, 2));
    for(auto begin = wc; begin != words.end(); ++begin)
    {
        cout << *begin << endl;
    }
}