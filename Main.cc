#include "Screen.cc"
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;

int main(){
    cin.tie(&cout);// just as example, as the tie alread is built by stardard library
    std::ostream *old_tie = cin.tie(nullptr);
    cin.tie(&cerr); // tie cin to cerr, but just as example, it is not a good idea
    cin.tie(old_tie); // rebuild the relation between cin and cout
}