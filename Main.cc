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
    bool inSub = false;
    vector<int> startIndex;
    // collect all the index of `s` which store the first element in `oldVal`
    for(int index = 0; index < s.size(); ++index)
    {
        if (s[index] == oldVal[0])
            startIndex.push_back(index);
    }
    vector<int> realSubIndex;
    while(startIndex.size() > 0)
    {
        if((s.size() - startIndex.back() + 1) < (oldVal.size()))
        {
            continue;
        }
        bool isSub = true;
        for(int startS = startIndex.back(), startOld = 0;
            startOld < oldVal.size(); // oldVal is the limit
            ++startS, ++startOld)
        {
            if (s[startS] != oldVal[startOld])
                isSub = false;
        }
        if(isSub)
            realSubIndex.push_back(startIndex.back());
        startIndex.pop_back();
    }
    for(int index : realSubIndex)
    {
        s.replace(index, oldVal.size(), newVal);
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