#include <utility>

struct Base {
    int memfcn();
};

struct Derived : Base {
    int memfcn(int); 
    // hides memfcn in the base even different functions!
};

class D : public B {
    // no constructors
};

D d;
D d2(d);
// error, because call the deleted copy constructor;
D d3(std::move(d));
// error, because implicitly uses D's deleted copy constructor


int main(int argc, char *argv[])
{
    return 0;
} 