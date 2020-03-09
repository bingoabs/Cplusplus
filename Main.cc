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
    auto f = [&li]() -> bool {
        return li ? li-- : 0;
    };
    int index = 100;
    while(index)
    {
        f();
        cout << li << " " << index-- << endl;
    }
    cout << "end" << endl;
}