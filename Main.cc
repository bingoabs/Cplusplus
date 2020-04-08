class Base {
    friend class Pal;
    int test;
    protected:
        int prot_mem;
};

class Sneaky : public Base { // private or protected [Base] would raise error!
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
};

class Pal {
    public:
        int f(Base b){return b.prot_mem;}
        int ff(Base b) { return b.test;};
        // friend can visit the private member
        // ok: Pal is a friend of Base
        // int f2(Sneaky s){return s.j;} 
        // error: Pal not friend of Sneaky
        // access to a base class is controlled by the base class, even inside a derived object
        int f3(Sneaky s) { return s.prot_mem;}
        // ok: Pal is a friend;
};


int main(int argc, char *argv[])
{
    return 0;
} 