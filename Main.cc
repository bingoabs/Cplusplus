#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::placeholders::_1;
#include "Message.cc"

struct LongDouble{
    LongDouble(double c = 0.0):a(c){};
    operator double(){
        std::cout << "ld double" << std::endl;
        return 1.0;
    };
    operator float(){
        std::cout << "ld float" << std::endl;
        return 2.0;
    }
    double a;
};

void calc(int a)
{
    std::cout << "cal int" << std::endl;
    return;
}

void calc(LongDouble a)
{
    std::cout << "calc ld" << std::endl;
    return ;
}
int main(int argc, char *argv[])
{
    double dval;
    calc(dval);
    return 0;
} 