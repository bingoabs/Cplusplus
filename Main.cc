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
    int li = 10;
    auto f = [&li](){return --li;};
    while(f())
        cout << li << endl;
}