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
    while(vec.size() > 1)
    {
        int first = std::stoi(vec.back());
        vec.pop_back();
        string oper = vec.back();
        vec.pop_back();
        int second = std::stoi(vec.back());
        vec.pop_back();
        int temp;
        if(oper == "+")
            temp = first + second;
        else if (oper == "*")
            temp = first * second;
        vec.push_back(std::to_string(temp));
    }
    return vec.back();
}

string pop(stack<string> &s)
{
    string temp = s.top();
    s.pop();
    return temp;
}
vector<string> popUntilRightBucket(stack<string> &s)
{
    vector<string> temp;
    while(s.top() != ")")
        temp.push_back(pop(s));
    pop(s);
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
    
    while (true)
    {
        if((left.size() == 1) && (right.size() == 0))
        {
            break;
        } else if (left.size() == 0)
        {
            vector<string> epr;
            while(right.size())
                epr.push_back(pop(right));
            string result = count(epr);
            left.push(result);
        } else
        {
            leftTop = pop(left);
            if (leftTop == "(")
            {
                vector<string> epr = popUntilRightBucket(right);
                string result = count(epr);
                left.push(result);
                while(right.size() > 0)
                    left.push(pop(right));
            } else {
                right.push(leftTop);
            }
        }
    }
    cout << pop(left) << " result " << endl;
}