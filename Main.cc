#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "Message.cc"

class getLen{
    public:
        getLen(const int i):num(i){}
        bool operator()(const std::string str)
        {
            return (str.size() == num);
        }
    private:
        int num;
};

int main(int argc, char *argv[])
{
    std::vector<std::string> ivec = {"a", "ab", "abc", "abcd", "abcde"};
    //std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    return 0;
} 