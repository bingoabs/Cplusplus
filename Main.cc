#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::list;
using std::stack;
// using namespace std::placeholders;
// we can directly use the names in this namespace!
bool isDigit(string s)
{
    if((s != "1")&&(s != "2")&&(s != "3")&&(s != "4")&&(s != "5")&&(s != "6"))
        return false;
    return true;
}
bool isSymbol(string s)
{
    if((s != "+") && (s != "-"))
        return false;
    return true;
}
string count(vector<string> vec){
    int result = 0;
    string last;
    for(auto begin = vec.begin(); begin != vec.end(); begin++)
    {
        if(begin == vec.begin())
        {
            result = std::stoi(*begin);
            continue;
        }
        if(*begin != "+")

    }
}

string pop(stack<string> s)
{
    string temp = s.top();
    s.pop();
    return temp;
}
vector<string> popUntilRightBucket(stack<string> s)
{
    vector<string> temp;
    while(s.top() != ")")
        temp.push_back(pop(s));
    return temp;
}
int main(int argc, char *argv[]){
    stack<string> left;
    stack<string> right;
    string leftTop;
    string rightTop;
    vector<string> data = {"3", "*", "(", "3", "+", "4", ")"};
    for(string d : data)
        left.push(d);
    
    while(true)
    {
        leftTop = pop(left);
        if (leftTop == "(")
            vector<string> expr = popUntilRightBucket(right);
            string result = count(expr);

    }
}