#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;

int main(int argc, char *argv[]){
    string value(argv[1]);
    vector<string> a = {"1", "2", "3", "4", "5", "6", "7", "8"};
    int numberAboveTen = count_if(a.begin(), a.end(), [value](string e) {return e > value;});
    cout << numberAboveTen << endl;
}