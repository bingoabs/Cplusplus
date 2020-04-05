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
        return 1.0;
    };
    operator float(){
        return 2.0;
    }
    double a;
};

int main(int argc, char *argv[])
{
    LongDouble ldObj;
    //int ex1 = ldObj;
    float ex2 = ldObj;
    return 0;
} 