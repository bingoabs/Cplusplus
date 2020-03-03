#include "Screen.cc"
#include <iostream>

int main(){
    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    myScreen.set('#').display(std::cout);
    blank.display(std::cout);
}