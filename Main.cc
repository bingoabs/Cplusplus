#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;
using std::list;
using std::stack;
void elimDups(vector<string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isBig(string a, vector<string>::size_type b) 
{
    return a.size() > b;
}
void print(const string &s){ cout << s << endl;}

void displayUsingFindif(vector<string> &words, vector<string>::size_type sz)
{
    // using find_if, return the first one which are true
    // auto wc = std::find_if(words.begin(), words.end(),
    // [sz](const string &a)
    // {return a.size() >= sz;});
    auto wc = std::find_if(words.begin(), words.end(), std::bind(isBig, _1, sz));
    auto count = words.end() - wc;
    cout << count << " " << " of length " << sz << " or longer" << endl;
    // std::for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    std::for_each(wc, words.end(), std::bind(print, _1));

}

// void displayUsingPartition(vector<string> &words, vector<string>::size_type sz)
// {
//     // using partition, put the `true` element in the head, 
//     // return the first iterator which point to the first `false` element.
//     // auto wc = std::partition(words.begin(), words.end(), [sz](const string &a) {return a.size() >> sz;});
//     auto wc = std::partition(words.begin(), words.end(), std::bind(isBig, _1, _2));
//     cout << endl;
//     auto count = words.begin() - wc; 
//     cout << count << " " << " of length " << sz << " or longer" << endl;
//     // std::for_each(words.begin(), wc, [](const string &s) {cout << s << " ";});
//     std::for_each(words.begin(), wc, std::bind(print, _1));
// }

void biggies(vector<string> &words,
vector<string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
        {
            return a.size() < b.size();
        });
    displayUsingFindif(words, sz);
}

int main(int argc, char *argv[]){
    vector<string> words = {"b", "a", "c", "d", "a", "b"};
    biggies(words, words.size());
    for(auto a : words)
        cout << a << " ";
    cout << endl;
}