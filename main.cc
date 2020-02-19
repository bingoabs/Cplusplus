#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word;
    vector<string> text;
    while (cin >> word)
    {
        text.push_back(word);
    };
    for(auto a : text)
    {
        cout << a << endl;
    };
}