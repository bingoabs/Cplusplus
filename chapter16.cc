#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include <string>
#include <type_traits>

using std::begin;
using std::end;
using std::vector;
using std::endl;
using std::cout;

// template <typename T> int compare(const T &v1, const T &v2)
// {
//     if (v1 > v2) return -1;
//     if (v2 > v1) return 1;
//     return 0;
// }

// struct Example {
//     public:
//         Example(int num):price(num){}
//         bool operator>(const Example&) const;
//         // withou the "const", the "rhs.get_price" can't run
//         // due to the rhs is a const Example,
//         // it only can invoke the const members.
//         // but the regular Example can call both const and non-const member
//         int get_price() const {return price;}
//     private:
//         int price; 
// };

// bool Example::operator>(const Example &rhs) const
// {
//     return (this->get_price() > rhs.get_price());
// }

// int main()
// {
//     cout << compare<Example>(Example(100), Example(10)) << endl;
//     cout << compare<Example>(Example(10), Example(100)) << endl;
//     return 0;
// }

// template <typename inputiterator, typename input>
// inputiterator find(inputiterator beg, inputiterator end, input val)
// {
//     inputiterator start;
//     for(start = beg; start != end; start++)
//         if (*start == val) break;
//     if (*start == val)
//         return start;
//     return end;
// }

// int main()
// {
//     vector<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9};
//     cout << (find(l.begin(), l.end(), 100) == l.end()) << endl;
//     cout << *find(l.begin(), l.end(), 2) << endl;
//     return 0;
// }

// template <int Size> void print(int (&arr)[Size])
// {
//     for(int* beg = begin(arr); beg != end(arr); beg++)
//         cout << *beg << endl;
// }

// int main()
// {
//     int a[] = {1, 2, 3, 4, 5, 6};
//     print(a);
// }


// ---------------------------------------------
// ---------------------------------------------

// template <int Size> constexpr int GetSize(int (&arr)[Size]){
//     return Size;
// };

// int main()
// {
//     int arr[] = {100, 10, 1};
//     cout << GetSize(arr) << endl;
// }

// template <typename T> class Blob {
//     public:
//         typedef T value_type;
//         typedef typename std::vector<T>::size_type size_type;
//         // The C++ treat it is the member by domain reference.
//         // So it need use typename to prove it is the type, not member.
//         Blob();
//         Blob(std::initializer_list<T> il);
//         size_type size() const {return data->size();}
//         bool empty() const { return data->empty();}
//         void push_back(const T &t) { data->push_back(t);}
//         void push_back(T &&t) {data->push_back(std::move(t));}
//         void pop_back();
//         T& back();
//         T& operator[](size_type i);
//     private:
//         std::shared_ptr<std::vector<T>> data;
//         void check(size_type i, const std::string &msg) const;
// };
// // member function defined outside class declare:
// // template <typename T> ret-type Blog<T>::member-name(parameter-list);

// template <typename T>
// void Blob<T>::check(size_type i, const std::string &msg) const
// {
//     if (i >= data->size())
//         throw std::out_of_range(msg);
// }

// template <typename T> T& Blob<T>::back()
// {
//     check(0, "bakc on empty Blob");
//     return data->back();
// }
// template <typename T>
// T& Blob<T>::operator[](size_type i)
// {
//     // if i is too big, check will throw, preventing access to a nonexistent element
//     check(i, "subscript out of range");
//     return (*data)[i];
// }

// template <typename T> void Blob<T>::pop_back()
// {
//     check(0, "pop_back on empty Blob");
//     data->pop_back();
// }

// template <typename T>
// Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()){}

// template <typename T>
// Blob<T>::Blob(std::initializer_list<T> il):
//     data(std::make_shared<std::vector<T>>(il)){}


// ---------------------------------------------
// ---------------------------------------------

// template <typename> class BlobPtr;
// template <typename> class Blob; // needed for parameters in operator==
// template <typename T> 
//     bool operator==(const Blob<T>&, const Blob<T>&);

// template <typename T> class Blob {
//     // each instantiation of Blob grants access to the version of 
//     // BlobPtr and the equality operator instantiated with the same type
//     friend class BlobPtr<T>;
//     friend bool operator==<T>
//         (const Blob<T>&, const Blob<T>&);
//     // other members are unchange.
// };

// Blob<char> ca; // BlobPtr<char> and operator==<char> are friends
// Blob<int> ia; // BlobPtr<int> and operator==<int> are friends

/*
The members of BlobPtr<char> may access the non-public parts of ca(or
any other Blob<char> object), but ca has no special access to ia(or any other Blob<int>) or 
to any other instantiation of Blob.
*/

// ---------------------------------------------
// ---------------------------------------------

// template <typename T> class Pal;
// class C { 
//     // C is an ordinary, nontemplate class
//     friend class Pal<C>; // Pal instantiated with class C is a friend to C
//     // all instances of Pal2 are friends to C;
//     // no forward declaration required when we befriend all instantiations
//     template <typename T> friend class Pal2;
// };

// template <typename T> class C2 {
//     // C2 is itself a class template
//     // each instantiation of C2 has the same instance of Pal as a friend
//     friend class Pal<T>; // a template declaration for Pal must be in scope;

//     // all instances of Pal2 are friends of each instance of C2, prior declaration needed
//     template <typename X> friend class Pal2;

//     // Pal3 is a nontemplate class that is a friend of every instance of C2
//     friend class Pal3; // prior declaration for Pal3 not needed; 
// };
// To allow all instantiations as friends, the friend declaration must use template parameter(s)
// that differ from those used by the class itself.

// ---------------------------------------------
// ---------------------------------------------

// Under the new standard, we can make a template type parameter a friend
// template <typename Type> class Bar {
//     friend Type; // grants access to the type used to instantiate Bar
// };
// Here we say that whatever type is used to instantiate Bar is a friend.
// Thus, for some type named Foo, Foo would be a friend of Bar<Foo>, Sales_data a friend of 
// Bar<Sales_data>, and so on.

// ---------------------------------------------
// ---------------------------------------------
// template <typename T> using twin = pair<T, T>;
// template <typename T> using partNo = pair<T, unsigned>;
// partNo<string> books; // books is a pair<string, unsigned>
// partNo<Vehicle> cars; // cars is a pair<Vehicle, unsigned>
// partNo<Student> kinds; // kids is a pair<Student, unsigned>

// ---------------------------------------------
// ---------------------------------------------

// template <typename T> class Foo {
//     public:
//         static std::size_t count() {return ctr;}
//         // other interface members
//     private:
//         static std::size_t ctr;
//         // other implementation members
// };

// Foo is a class template that has a public static member function 
// named count and a private static data member named ctr.
// Each instantiation of Foo has its own instance of the static members.

// ---------------------------------------------
// ---------------------------------------------
// class Meter;
// template <typename T> class Screen;
// template <typename T> std::ostream& operator<<(std::ostream&, Screen<T>&);
// template <typename T> std::iostream& oprator>>(std::instream&, Screen<T>&);

// template <typename T> class Screen {
//     Meter height, width;
//     friend std::ostream& operator<<<T>(std::ostream&, Screen&);
//     friend std::istream& operator>><T>(std::istream&, Screen<T>&);
// };
// Actually, it don't need the friend, only use public is okay

// template <typename T> std::ostream& operator<<<T>(std::ostream& is, Screen<T> &s)
// {
//     cout << s.height << " " << s.width << endl;
//     return is;
// }

// ---------------------------------------------
// ---------------------------------------------

// template <typename Foo> Foo calc(const Foo& a, const Foo& b)
// {
//     Foo tmp = a; // tmp has the same type as the parameters and return type
//     // ...
//     return tmp; // return type and parameters have the same type
// }

// typedef double A;
// template <typename A, typename B> void f(A a, B b)
// {
//     A tmp = a; // tmp has same type as the template parameter A, not double
//     double B; // error: redeclares template parameter B
// }

// template <typename T>
// typename T::value_type top(const T& c)
// {
//     if(c.empty())
//         return c.back();
//     else 
//         return typename T::value_type();
// }

// ---------------------------------------------
// ---------------------------------------------

// default Template Arguments

// compare has a default template argument, less<T>
// and a default function argument, F()
// template <typename T, typename F = less<T>>
// int compare(const T &v1, const T &v2, F f= F())
// the F f = F(), as the F is a type, so can't be F f = F;
// still weird, but maybe now is better one.
// {
//     if (f(v1, v2)) return -1;
//     if (f(v2, v1)) return 1;
//     return 0;
// }

// template <typename Loop> typename void Print(Loop &l)
// {
//     typename Loop::size_type len = l.size();
//     for(auto index = 0; index != len; index++)
//         cout << l[index] << endl;
//     return;
// }

// template <typename It> void Print(typename It::iterator begin, typename It::iterator end)
// {
//     for(auto cur = begin; cur != end; cur++)
//         cout << *cur << " ";
//     cout << endl;
//     return;
// }

// int main()
// {
//     vector<int> ls = {1, 2, 3, 4, 5, 6};
//     Print<vector<int>>(ls.begin(), ls.end());
// }

// ---------------------------------------------
// ---------------------------------------------

// Member Templates
// A class -either an ordinary class or a class template - 
// may have a member function that is itself a template.
// Such members are referred to as member templates.
// Member templates may not be virtual.

// class DebugDelete {
//     public:
//         DebugDelete(std::ostream &s = std::cerr): os(s) {}
//         // as with any function template, the type of T is deduced by the compiler
//         template <typename T> void operator()(T *p) const 
//         {
//             os << "deleting unique_ptr" << std::endl;
//             delete p;
//         }
//     private:
//         std::ostream &os;
// };

// define the ordinary variable outside function will raise error:
// this declaration has no storage class or type specifier
// int main()
// {
//     double *p = new double;
//     DebugDelete d; // an object that can act like a delete expression
//     d(p); // calls DebugDelete::operator()(double*), whihc deletes p
//     int* ip = new int;
//     // calls operator()(int*) on a temporary DebugDelete object
//     DebugDelete()(ip);

//     std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
//     // DebugDelete() inits a DebugDelete instance

//     // Here, we've said that p's deleter will have type DebugDelete, and
//     // we have supplied an unnamed object of that type in p's constructor.
// }

// template <typename T> class Blob {
//     template <typename It> Blob(It b, It e);
//     template <typename I> Blob(typename I::iterator a, typename I::iterator b);
//     // ...
//     std::make_shared<std::vector<t>> data;
// };

// template <typename T>
// template <typename It>
//     Blob<T>::Blob(It b, It e):
//         data(std::make_shared<std::vector<T>>(b, e)){}
// #include <list>
// #include <string>
// using std::string;
// using std::list;
// int main()
// {
//     int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     list<const char*> w = {"now", "is", "the", "time"};
//     // instantiates the Blob<int> class 
//     // and the Blob<int> constructor that has two int* parameters
//     Blob<int> a1(begin(ia), end(ia));
//     // instantiates the Blob<int> constructor that has 
//     // two vector<long>::iterator parameters
//     Blob<int> a1(vi.begin(), vi.end());
//     // instantiates the Blob<string> class and the Blob<string>
//     // constructor that has two (list<const char*>::iterator parameters
//     Blob<string> a3(w.begin(), w.end());
// }

// extern template class Blob<string>;
// extern template int compare(const int&, const int &);

// ---------------------------------------------
// ---------------------------------------------

// template <typename T> T fobj(T, T); // arguments are copied
// template <typename T> T fref(const T&, const T&); // references 

// string s1("a value");
// const string s2("another value");
// fobj(s1, s2); // calls fobj(string, string); const is ignore
// // const can be ignored, because it is "value", like using a 
// // const to initialize a non-const value;
// // if it is the reference or pointer, it can't ignore "const"
// fref(s1, s2); // calls fref(const string&, const string&)
//     // uses premissible conversion to const on s1

// int a[10], b[42];
// fobj(a, b); // calls f(int*, int*)
// fref(a, b); // error: array types don't match in the length
// // length is part of the array type

// the string literal is the char[].

// template <typename T> f1(T, T);

// template <typename T1, typename T2, typename T3>
// T1 sum(T2, T3);
// auto val3 = sum<long long>(i, lng); // long long sum(int, long)
// // T2 and T3 are inferred from the argument types

// int main()
// {
//     int i = 0, j = 42, *p1 = &i, *p2 = &j;
//     const int *cp1 = &i, *cp2 = &j;
//     // f1(p1, cp1); // first check whether it is the same, then check the conversion
// }

// template <typename T> T Max(T, T);
// Max<double>(Dou, Int);

// template <typename T>
// auto fcn(T beg, T end) -> decltype(*beg) // deduce an reference
// {
//     // process the range;
//     return *beg; // return a reference to an element from the range
// }

// template <typename It>
// auto fnc2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type
// {
//     // process the range
//     return *beg; // return a copy of an element from the range
// }

// template <typename F, typename T1, typename T2>
// void flip1(F f, T1 t1, T2 t2)
// {
//     f(t2, t1);
// }
// The template works fine until we want to use it to call a function 
// that has a reference parameter

// template <typename F, typename T1, typenam T2>
// void flip2(F f, T1 &&t1, T2 &&t2)
// {
//     f(t2, t1);
// }

/*
A function parameter that is an rvalue reference to a template type
parameter (i.e T&&) preserves that constness and lvalue/rvalue property of its
corresponding argument
*/

// void g(int &&i, int & j)
// {
//     cout << i << " " << j << endl;
// }

// template <typename F, typename T1, typename T2>
// void flip3(F f, T1 &&t1, T2 &&t2)
// {
//     f(std::forward<T2>(t2), std::forward<T1>(t1));
// }
// // std::forward preserve the lvalue/rvalue nature of its given argument

// ---------------------------------------------
// ---------------------------------------------

// Overloaded function templates
// template <typename T> string debug_rep(const T &t)
// {
//     ostringstream ret;
//     ret << t; // uses T's output operator to print a representation of t
//     return ret.str(); // return a copy of the string to which ret is bound
// }

// template <typename T> string debug_rep(T *p)
// {
//     ostringstream ret;
//     ret << "pointer: " << p; // print the pointer's own value
//     if(p)
//         ret << " " << debug_rep(*p); // print the value to which p points
//     else
//         ret << " null pointer"; // or indicate that the p is null
//     return ret.str(); // return a copy of the string to which ret is bound;
// }

// // print strings inside double quotes
// string debug_rep(const string &s)
// {
//     return '"' + s = '"';
// }

// string debug_rep(char *)
// {
//     return debug_rep(string(p));
// }

// string debug_rep(const char *p)
// {
//     return debug_rep(string(p));
// }

/*
Declare every function in an overload set before you define any of the function.
That way you don't have to worry whether the compiler will instantiate a call 
before it sees the function you intended to call
*/

// ---------------------------------------------
// ---------------------------------------------

//Args is a template parameter pack; rest is a function parameter pack
// Args represents zzero or more template type parameters
// rest represents zero or more function parameters
// template <typename T, typename... Args>
// void foo(const T &t, const Args& ... rest)
// {
//     cout << sizeof...(Args) << " " << sizeof...(rest) << endl;
//     // according to the result, the two value are idnetical.
// }

// int main()
// {
//     int i = 0; double d = 3.14; std::string s = "how now brown cow";
//     foo(i, s, 42, d); // three parameters in the pack
//     foo(s, 42, "hi"); // two parameters in the pack
//     foo(d, s); // one parameter in the pack
//     foo("hi"); // empty pack
// }
// The compiler will instantiate four different instances of `foo`

// void foo(const int&, const string&, const int&, const double&);
// void foo(const string&, const int&, const char[3]&);
// void foo(const doubl&, const string&);
// void foo(const char[3]&);
// // When we need to know how many elements there are in a pack we can use the sizeof...operator

// template<typename ... Args> void g(Args ... args)
// {
//     cout << sizeof...(Args) << endl; // number of type parameters
//     cout << sizeof...(args) << endl; // number of function parameters
// }

/*
// Variadic functions are used when we know neighter the number nor the 
// types of the arguments we want to process
    Variadic functions are often recursive. The first call processes the first argument in the pack
    and calls itself on the remaing arguments.
*/

// function to end the recursion and print the last element
// this function must be declared before the variadic version of porint is defined
// template<typename T>
// ostream &print(ostream &os, const T &t)
// {
//     return os << t; // no separator after the last element in the pack
// }
// // this version of print will be called for all but the last element in the pack
// tempalte <typename T, typename...Args>
// ostream &print(ostream &os, const T &t, const Args&... rest)
// {
//     os << t << ", "; // print the first argument
//     return print(os, rest...); // recursive call; print the othjer arguments
// }
// Due to the C++ don't have the tool to extract the first element of `rest`, 
// so the template has to define a `const T &t`
// beautiful style: rest.first, rest.rest
// Or maybe add `sizeof...(rest)` to find the last type

// call debug_rep on each argument in the call to print
// template <typename... Args>
// ostream &errorMsg(ostream &os, const Args&... rest)
// {
//     // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
//     return print(os, debug_rep(rest)...);
//     // print(os, debug_rep(rest...)); // error: no matching function to call
// }

// class Test{
//     public:
//         Test():selfNum(num){
//             cout << " init " << endl;
//             num++;
//         }
//         int Get(){
//             return selfNum;
//         }
//         Test(const Test &r){
//             cout << "into copy" << endl;
//             selfNum = r.selfNum;
//         }
//     private:
//         int selfNum;
//         static int num;
// };

// int Test::num = 0;

// int main()
// {
//     vector<Test> l;
//     Test a;
//     cout << "a: " << a.Get() << endl;
//     l.push_back(Test());
//     cout << "separator One" << endl;
//     // copy a to the argument,
//     // then copy the argument into vector
//     l.push_back(a);
//     cout << "separator Two" << endl;
//     Test& a1 = a;
//     cout << "separator Three" << endl;
//     // look like the copy by the reference to get a real Test
//     // the use the Test to do the push_back()
//     // so copy three time
//     l.push_back(a1);
//     cout << "separator Four" << endl;
//     Test b;
//     cout << "b: " << b.Get() << endl;
//     cout << "a: " << a.Get() << endl;
// }

// template<typename... Args>
// void fun(Args&&... args) // expands Args as a list of rvalue references
// {
//     // the argument to work expands both Args and args
//     work(std::forward<Args>(args)...);
// }

// special version of compare to handle pointers to character arrays
// template <>
// a reference to a const pointer to const char...
// int compare(const char* const &p1, const char* const &p2)
// {
//     return strcmp(p1, p2);
// }
/*
Templates and their specializations should be declared in the same hader file
Declarations for all the templates with a given name should appear first,
followed by any specializations of those templates
*/

// open the std namespace so we can specialize std::hash
// namespace std{
// }// close the std nampspace; not : no semicolon after the close curly

// namespace std {
// template <> // we're defining a specialization with
// struct hash<Sales_data> // the template parameter of Sales_data
// {
//     // the type used to hash an unordered container must define these types
//     typedef size_t result_type;
//     typedef Sales_data argument_type; // by default this type needs ==
//     size_t operator()(const Sales_data& s) const;
//     // our class uses synthesized copy control and default constructor
// };

// size_t 
// hash<Sales_data>::operator() (const Sales_data& s) const
// {
//     return hash<string>()(s.bookNo) ^
//         hash<unsigned>()(s.units_sold) ^
//         hash<double>()(s.revenue);
//     // here the hash<string> is a instantiation,
//     // so hash<string>() is unnamed object 
//     // so must add `()`, then call it
// }

// template <class T> class std::hash; // needed for the friend declaration
// class Sales_data {
//     firend class std::hash<Sales_data>;
//     // other members as before
// };


// ---------------------------------------------
// ---------------------------------------------

// template <class T> struct remove_reference {
//     typedef T type;
// };
// // partial specializations that will be used fo lvalue and rvalue references
// template <class T> struct remove_reference<T&> // lvalue reference
// {
//     typedef T type;
// };
// template <class T> struct remove_reference<T&&> // rvalue references 
// {
//     typedef T type;
// };

// in main()
// {
//     int i;
//     // decltype(42) is int, uses the original template
//     // 42 is the prvalue, so return the original type, not rvalue
//     remove_reference<decltype(42)>::type a;
//     // decltype(i) is int&, uses first (T&) partial specialization
//     // return left reference to the lvalue
//     remove_reference<decltype(i)>::type b;
//     // decltype(std::move(i)) is int&&, uses second(i.e. T&&) partial specialization
//     remove_reference<decltype(std::move(i))>::type c;
//     // All three variables, a, b and c, have type int.
// }


// template<typename T> struct Foo {
//     Foo(const T &t = T()): mem(t){}
//     void Bar() { /* .... */}
//     T mem;
//     // other membners of Foo
// };

// template<> // we're specializing a template
// void Foo<int>::Bar() // we/re specializing the Bar member of Foo<int>
// {
//     // do whatwever specialized processing that applies to ints
// }
// Here we are specializing just one member of the Foo<int> class.
// The other members of Foo<int> will be supplied by the Foo template;

// int main()
// {
//     Foo<std::string> fs; // instantiates Foo<string>::Foo()
//     fs.Bar(); // instantiates Foo<string>::Bar()
//     Foo<int> fi; // instantiates Foo<int>::Foo()
//     fi.Bar() // uses our specialization of Foo<int>::Bar()
// }

template <typename T> int count(vector<T> &t, T val)
{
    int num = 0;
    for(auto beg = t.begin(); beg != t.end(); beg++)
    {
        if(*beg == val)
            num++;
    }
    return num;
}
#include <cstring>
using std::strcmp;

template <> int count(vector<const char*> &t, const char* val)
{
    int num = 0;
    for(auto beg = t.begin(); beg != t.end(); beg++)
    {
        if (!strcmp(*beg, val))
            num++;
    }
    return num;
}
int main()
{
    // vector<int> lt = {1, 2, 3, 4, 5, 1, 23, 4, 5, 6, 10};
    // vector<std::string> ls = {"a", "b", "c", "d", "c"};
    // cout << count(lt, 5) << endl;
    // cout << count(ls, std::string("c")) << endl;
    vector<const char*> la = {"abc", "acd", "abc", "abc"};
    // list the content in `la`
    // for(const char* e : la)
    // {
    //     // ends with '\0'
    //     for(int i = 0; i < 10; i++)
    //         cout << *(e + i) << " ";
    //     cout << endl;
    //     break;
    // }
    const char* a = "abc";
    cout << count(la, a) << endl;
}