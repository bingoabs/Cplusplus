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

class A {
    virtual void foo()
    {
        cout << "A" << endl;
    }
};
class B : virtual public A {
    virtual void foo()
    {
        cout << "B" << endl;
    }
};
class C : public B {
    virtual void foo()
    {
        cout << "C" << endl;
    }
};

class D : public B, virtual public A { // To D and B need set the A as the virtual class
    virtual void foo()
    {
        cout << "D" << endl;
    }
};

int main()
{
    B *pb = new B;
    C *pc = dynamic_cast< C* >(pb); 
    // if not define the virtual function, it will raise
    // 运行时 dynamic_cast 的操作数必须包含多态类类型
    cout << boolalpha << (pc == 0) << endl;
}