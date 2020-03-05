#include "Screen.cc"
#include <iostream>

/*
std::istream is a kind of type or object
std::cin is one object of std::istream
*/
std::ostream &process_input(std::istream& a){
    std::cout << "this function used to read input";
    std::cout.clear();
    return std::cout;
}

int main(){
    auto old_state = std::cin.rdstate(); // record the old istream status
    std::cin.clear(); // make istream work
    process_input(std::cin); // use the istream 
    std::cin.setstate(old_state); // set the istream back to old status
    // std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
    // reset the `failbit` and `badbit`, but keep the `eofbit`
}