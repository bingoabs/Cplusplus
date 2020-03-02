#include "Sales_data.cc"

int main(){
    Sales_data a("another_name", 100, 10);
    std::cout << a.isbn() << std::endl;
    return 0;
}