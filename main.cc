#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;

int main()
{
    string word;
    vector<string> text;
    while (cin >> word)
    {
        text.push_back(word);
    }
}