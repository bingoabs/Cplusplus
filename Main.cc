#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
#include <numeric>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
// using namespace std::placeholders;
// we can directly use the names in this namespace!

class Example {
    public:
        static double rate = 6.5;
        static constexpr int vecSize = 20;
        static vector<double> vec(10);
};
int main(int argc, char *argv[]){
    int vec = 10;
    vector<int> nums(vec);
    vector<string> strings = {"1", "2", "3", "4"};
    for(string str : strings)
        nums.push_back(std::stoi(str));
    cout << std::accumulate(nums.begin(), nums.end(), 0) << endl;
}