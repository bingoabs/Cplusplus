#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    std::vector<std::string> a = {"a", "ab", "abc", "abcd", "abcde"};
    auto wc = std::find_if(a.begin(), a.end(), getLen(4));
    std::cout << *wc << std::endl;
    return 0;
} 