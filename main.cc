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
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while(cin >> grade){
        if(grade <= 100)
        {
            ++scores[grade/10];
        } else {
            cout << "The value is invalid" << endl;
            break;
        }
    };
    vector<int> ivec;
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    {
        ivec.push_back(ix);
    };
}