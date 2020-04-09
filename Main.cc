#include <utility>

class Base {};
class D: public Base {
public:
    // by default, the base class default constuctor initializes the base part of an object
    // to use the copy or move constructor, we must explicitly call that
    // constructor in the constructor initializer list
    D(const D& d): Base(d) // copy the base members
        /* initializers for members of D */ {/* .... */}
    D(D&& d): Base(std::move(d)) // move the base members
        /* initializers for members of D */ { /* ... */}
};

class FinalClass1
{
public:
      static FinalClass1* GetInstance()
      {
            return new FinalClass1;
      }
 
      static void DeleteInstance( FinalClass1* pInstance)
      {
            delete pInstance;
            pInstance = 0;
      }
private:
      FinalClass1() {}
      ~FinalClass1() {}
};

class zero {
    private:
        zero(){}
        zero(int x){System.out.println("hello");}
        void doSome(){System.out.println(234);}
    public:
        void constructor(){zero.data.doSome();}
        static zero data=new zero(6);
};

public class first{
    first(){zero.data.constructor();}
    public static void main(String[] args){first a=new first();}
};

int main(int argc, char *argv[])
{
    return 0;
} 