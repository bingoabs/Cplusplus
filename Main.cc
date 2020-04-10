#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;

// Put (Smart) Pointers, Not Objects, in Containers

class Quote{
    int num;
public:
    Quote():num(10){}
    virtual int net_price(){
        return num;
    }
};

class Bulk_quote : public Quote {
public:
    Bulk_quote():Quote(){
        num = 100;
    }
    int net_price() override
    // if don't overrid the virtual function
    // then the return value is 10!
    {
        return num;
    }
    int num;
};

int main(int argc, char *argv[])
{
    vector<Quote> ql;
    for(int i = 0; i < 10; i++)
    {
        Bulk_quote a;
        ql.push_back(a);
    }
    cout << std::accumulate(ql.begin(), 
        ql.end(), 
        0, 
        [](int a, Quote b){return a + b.net_price();}) 
    << endl;
    // The lambda using Quote, so the result must use the Quote's net_price and field num!
    return 0;
} 