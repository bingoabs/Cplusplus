#include "Screen.cc"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::endl;


int main(int argc, char *argv[]){
    size_t v1 = 42;
    auto f2 = [&v1] { return ++v1;};
    v1 = 0;
    auto j = f2();
    cout << j << endl;
    auto returnLambda = [](int i) -> int {
        if (i > 0)
            return -i;
        else 
            return i;
    };
    cout << returnLambda(10) << endl;
}