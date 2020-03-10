#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
// using namespace std::placeholders;
// we can directly use the names in this namespace!

string replaceSubstring(string s, string oldVal, string newVal){
    if(!s.size() || !oldVal.size()){
        cout << s.size() << " " << oldVal.size();
        return string("");
    }
    string::iterator begin = s.begin();
    while((begin + oldVal.size()) <= s.end())
    {
        string::iterator rawBegin = begin;
        string::iterator ob = oldVal.begin();
        for(;ob != oldVal.end(); ob++, begin++)
        {
            if(*begin != *ob)
                break;
        }
        if(ob != oldVal.end())
        {
            // don't match the oldVal
            if(ob == oldVal.begin())
                begin++;
            continue;
        }
        string::iterator iter = s.erase(rawBegin, rawBegin + oldVal.size());
        iter = s.insert(iter, newVal.begin(), newVal.end());
        begin = iter + newVal.size();
    }
    return s;
}

int main(int argc, char *argv[]){
    //.\a.exe test t AAA
    string s(argv[1]);
    string oldVal(argv[2]);
    string newVal(argv[3]);
    string sa = replaceSubstring(s, oldVal, newVal);
    cout << sa << endl;
}