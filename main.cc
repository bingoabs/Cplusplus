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
    if(s.begin() == s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    };

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);
    }
}