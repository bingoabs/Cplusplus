#include <iostream>
#include <vector>
#include "Message.cc"

struct equal {
    public:
        equal()=default;
        bool operator()(const int &a, const int &b)
        {
            return (a == b);
        }
};

int main(int argc, char *argv[])
{
    equal e;
    std::cout << e(10, 100) << e(10, 10) << std::endl;
    return 0;
} 