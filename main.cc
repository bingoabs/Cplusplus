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
    vector<string> text;
    string word;
    while (cin >> word)
    {
        text.push_back(word);
    };
    cout << "Finish the input, print the upper word line by line" << endl;
    for (auto &word : text)
    {
        for(auto &c : word)
        {
            c = toupper(c);
        }
    }
    for (auto word : text)
    {
        cout << word << endl;
    };
}