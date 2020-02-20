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
    string s("some string");
    // upper the first letter in the string
    if(s.begin() == s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    };
    // upper the first word in the string
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);
    };
    // (*it).empty() == it->empty
    vector<string> text;
    text.push_back("first word");
    text.push_back(" ");
    text.push_back("second word");
    for(auto it = text.cbegin();
    it != text.cend() && !it->empty(); ++it)
        cout << *it << endl;
    
}