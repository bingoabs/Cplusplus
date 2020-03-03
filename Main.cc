#include "Screen.cc"
#include <iostream>

struct X {
    friend void f();
    // X() {f();}; // Friend declare is not the real function declare!
    void g();
    void h();
};
//void X::g() { return f()}; // `f` is not defined
void f(); // Friend `f` is declared;
void X::h() { return f();}; // True
int main(){
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}