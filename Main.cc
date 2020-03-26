#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
#include <iterator> // for the istream_iterator
#include <forward_list>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include <istream>
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;
using std::list;
using std::stack;
using std::forward_list;
using std::map;
using std::set;
using std::multiset;
using std::shared_ptr;
using std::unique_ptr;
using std::allocator;
using std::ifstream;

class Employee{
    string Name;
    int Id;
    static int Num;
public:
    Employee() = default;
    Employee(string name):Name(name), Id(Num++){}
    int GetId();
};
int Employee::Num = 0;
int Employee::GetId(){
    return Id;
}

int main(int argc, char *argv[])
{
    Employee a("one"), b("two");
    cout << a.GetId() << endl;
    cout << b.GetId() << endl;
    Employee *c = new Employee();
    Employee *d = new Employee;
    cout << c->GetId() << endl;
    cout << d->GetId() << endl;
} 