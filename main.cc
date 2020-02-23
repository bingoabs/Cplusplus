#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// using int_array = int[4]; new way to get an alias
// typedef int int_array[4]; old way to get an alias
int main()
{
    //cond?(expr1):(expr2);
    int grade;
    cin >> grade;
    string finalGrade = (grade < 60)?"failed":"success";
    finalGrade = (grade > 90) ? "high pass"
        : (grade < 60)? "failed" : "success";
    cout << finalGrade << endl;
}