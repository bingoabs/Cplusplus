#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::placeholders::_1;
#include "Message.cc"

class getLen{
    public:
        getLen(const int i):num(i){}
        bool operator()(const std::string str)
        {
            return (str.size() == num);
        }
        operator int() const {
            return num;
        }
    private:
        int num;
};

int main(int argc, char *argv[])
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    getLen a(100);
    int r = a;
    std::cout << r << std::endl;
    return 0;
} 