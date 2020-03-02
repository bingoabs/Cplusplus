#include "Chapter6.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::initializer_list;
using std::vector;

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    public:
        Sales_data() = default;
        Sales_data(const string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) {}
        Sales_data(const string &s):bookNo(s){}
        Sales_data(std::istream&);
        string isbn() const{return bookNo;}
        Sales_data &combine(const Sales_data&);
    private:
        double avg_price() const
            {return units_sold? revenue/units_sold : 0;}
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

Sales_data::Sales_data(std::istream &is)
{
    // even the `read` is called by the constructor in Sales_data,
    // but if the `read` uses the private memeber, the compilation would fail.
    // And after declare the `read` is one of Sales_data's friends, it works.
    read(is, *this);
}


// std::ostream &print(std::ostream &os, const Sales_data &item)
// {
//     os << item.isbn() << " " << item.units_sold << " "
//         << item.revenue << " " << item.ave_price();
//     return os;
// }



int main(){
    return 0;
}