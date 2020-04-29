#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// void *operator new(size_t size)
// {
//     cout << "defined new operator" << endl;
//     if (void *mem = malloc(size))
//         return mem;
//     else 
//         throw bad_alloc();
// }

// void operator delete(void *mem) noexcept 
// {
//     cout << "defined delete operator" << endl;
//     free(mem);
// }
// void operator delete[](void *mem) noexcept 
// {
//     cout << "defined delete operator 2" << endl;
//     free(mem);
// }
// class T {
//     public:
//         T(int a): num(a){};
//         int num;
// };

// class T2 {
//     public:
//     T2(int a) {
//         _nums.push_back(a);
//     }
//     vector<int> _nums;
// };

// int main()
// {
//     // Below are the results: So only the class with Vector will invoke the `delete` operator
//     // init
//     // defined new operator
//     // First
//     // defined new operator
//     // Second
//     // defined new operator // one for T2 object
//     // defined new operator // one for the vector member
//     // defined delete operator
//     // Third
//     // defined delete operator 2
//     // end
//     cout << "init" << endl;
//     int *a = new int(10);
//     delete a;
//     cout << "First" << endl;
//     T *t = new T(10);
//     delete t;
//     cout << "Second" << endl;
//     T2 *t2 = new T2(100);
//     delete t2;
//     cout << "Third" << endl;
//     int *b = new int[10];
//     delete []b;
//     cout << "end" << endl;
// }

// class A {
//     virtual void foo()
//     {
//         cout << "A" << endl;
//     }
// };
// class B : virtual public A {
//     virtual void foo()
//     {
//         cout << "B" << endl;
//     }
// };
// class C : public B {
//     virtual void foo()
//     {
//         cout << "C" << endl;
//     }
// };

// class D : public B, virtual public A { // To D and B need set the A as the virtual class
//     virtual void foo()
//     {
//         cout << "D" << endl;
//     }
// };

// int main()
// {
//     B *pb = new B;
//     C *pc = dynamic_cast< C* >(pb); 
//     // if not define the virtual function, it will raise
//     // 运行时 dynamic_cast 的操作数必须包含多态类类型
//     cout << boolalpha << (pc == 0) << endl;
// }

// class A {
//     virtual void test()
//     {
//         cout << "A" << endl;
//     }
// };

// class B : public A {
//     virtual void test()
//     {
//         cout << "B" << endl;
//     }
// };

// int main()
// {
//     A* b = new B;
//     if(typeid(*b) == typeid(B))
//     {
//         cout << "true" << endl;
//     }
//     else {
//         cout << "false" << endl;
//     }

//     B* b2 = new B;
//     A &ba = *b2;
//     if(typeid(ba) == typeid(B))
//     {
//         cout << "true" << endl;
//     }
//     else {
//         cout << "false" << endl;
//     }
// }

// class A {};
// class B : public A {};
// class C : public B {};

// int main()
// {
//     cout << typeid(A).name() << endl;
//     cout << typeid(B).name() << endl;
//     cout << typeid(C).name() << endl;
//     cout << endl;
//     A *pa = new C;
//     cout << typeid(pa).name() << endl;

//     C cobj;
//     A& ra = cobj;
//     cout << typeid(&ra).name() << endl;

//     B *px = new B;
//     A& ra1 = *px;
//     cout << typeid(ra1).name() << endl;
// }

// struct A {
//     virtual void test()
//     {
//         cout << "A" << endl;
//     }
// };
// struct B : public A {
//     virtual void test()
//     {
//         cout << "B" << endl;
//     }
// };

// void print(A &a)
// {
//     a.test();
// }
// int main()
// {
//     B b = B();
//     print(b); // print 'B'
//     // so the reference can save the raw data.
// }

// enum color {red, yellow, green};
// // enum stoplight {red, yellow, green};  // repeat the `red` ...
// enum class peppers {red, yellow, green};

// color eyes = green; // the `green` duplication in `color` and `stoplight`!
// // peppers p = green; // error, should be peppers::green

// color hair = color::red; // right
// peppers p2 = peppers::red; // right 

// class Screen {
// public:
//     typedef std::string::size_type pos;
//     char get_cursor() const {
//         return contents[cursor];
//     }
//     char get() const;
//     char get(pos ht, pos wd) const;
//     static const std::string Screen::*data() {
//         return &Screen::contents;
//     }
//     static const pos Screen::*cur(){
//         return &Screen::cursor;
//     }
// private:
//     std::string contents;
//     pos cursor;
//     pos height, width;
// };

// // const string Screen::*pdata;
// // denote a pointer to the `const string` member of `Screen`

// // int main()
// // {
// //     const string Screen::*pdata;
// //     // pdata = &Screen::contents; // error, when the contents is private
// //     pdata = Screen::data();
// //     Screen myScreen, *pScreen = &myScreen;
// //     auto s = myScreen.*pdata;
// //     auto s2 = pScreen->*pdata;

// //     const Screen::pos Screen::*pcur;
// //     pcur = Screen::cur();
// //     cout << "end" << endl;
// // }

// int main()
// {
//     // char (Screen::*pmf) (Screen::pos, Screen::pos) const;
//     // // a pointer to the function member of Screen
//     // pmf = &Screen::get;
//     // char Screen::*p(Screen::pos, Screen::pos);
//     auto pmf1 = &Screen::get_cursor;
//     // pmf1 = &Screen::get; 
//     // error, need emplict to list the parameter list
//     // as the `get` has overload functions``````
//     cout << "end" << endl;
// }

class Token {
public:
    Token(): tok(INT), ival(0) {};
    Token(const Token &t) : tok(t.tok) {copyUnion(t);}
    Token &operator=(const Token&);
    ~Token() { if (tok == STR) sval.~string();}
    Token &operator=(const std::string&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    // void print()
    // {
    //     test.test();
    // }
private:
    enum {INT, CHAR, DBL, STR} tok; // class or struct can also use this format to define a member!
    // class {
    // public:
    //     void test(){
    //         cout << "test" << endl;
    //     }
    // } test;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    void copyUnion(const Token&);
};

Token &Token::operator=(int i)
{
    if(tok == STR) sval.~string();
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(const std::string &s)
{
    if(tok == STR)
        sval = s;
    else 
        new(&sval) string(s);
    tok = STR;
    return *this;
}