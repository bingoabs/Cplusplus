#include <iostream>

using namespace std;

// namespace Exercise {
//     int ivar = 0;
//     double dvar = 0;
//     const int limit = 1000;
// }

// int ivar = 0;
// using namespace Exercise;
// void manip() {
//     double dvar = 3.1415926;
//     int iobj = limit + 1;
//     ++Exercise::ivar; // right
//     // ++ivar; // error
//     ++::ivar;
// }

// namespace Exercise {
//     int ivar = 0;
//     double dvar = 0;
//     const int limit = 1000;
// }

// int ivar = 0;
// void manip() {
//     using namespace Exercise;
//     double dvar = 3.1415926;
//     int iobj = limit + 1;
//     // ++ivar; // still error!
//     ++::ivar;
// }

// class CAD {

// };

// class Vehicle {};

// class CADVehicl : public CAD, Vehicle {};

// int main()
// {
//     // Vehicle a = CADVehicl(); // error, the Vehicle part is private, 
//     // so can't cast to the Vehicle from CADVehicle
// }

// class A {
//     public:
//     virtual void test(){
//         cout << "A.test" << endl;
//     }
// };

// class B {
//     public:
//     virtual void test() {
//         cout << "B.test" << endl;
//     }
// };

// class C : public A, public B {
// public:
//     C(int n): num(n) {}
//     virtual void test() {
//         cout << "C.test: " << num << endl;
//     }
// private:
//     int num;
// };

// int main()
// {
//     A c1 = C(1);
//     B c2 = C(2);
//     c1.test(); // A.test
//     c2.test(); // B.test

//     C c3 = C(3);
//     A* a1 = &c3;
//     B* b1 = &c3;
//     a1->test(); // C.test: 3
//     b1->test(); // C.test: 3
// }

// struct Base {
//     void bar(int);
// protected:
//     int ival;
// };

// struct Derived1 : virtual public Base {
//     void bar(char);
//     void foo(char);
// protected:
//     char cval;
// };

// struct Derived2 : virtual public Base {
//     void foo(int);
// protected:
//     int ival;
//     char cval;
// };

// class VMI : public Derived1, public Derived2 {};

// int main()
// {
//     VMI a = VMI();
//     a.bar(12); // right, the Base version, not cover by the bar() in Derived1!
//     a.foo(12); // error, Derived1 and Derived2 have foo, even the parameters not same. 
// }
// Class, Base, D1, D2, MI, Class, Final  
