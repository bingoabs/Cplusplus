#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class Base {
    protected:
        int prot_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
};

void clobber(Sneaky &s){
    s.j = s.prot_mem = 0;
}

void clobber(Base &s){
    s.prot_mem = 0;
}

int main(int argc, char *argv[])
{
    return 0;
} 