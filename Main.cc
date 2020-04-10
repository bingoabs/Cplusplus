#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include <string>
#include <set>

using std::string;
using std::vector;
using std::cout;
using std::endl;


// Put (Smart) Pointers, Not Objects, in Containers

class Quote{
    int price;
    string bns;
public:
    Quote(string bn):price(10), bns(bn){}
    virtual int net_price(){
        return price;
    }
    string isbn()
    {
        return bns;
    }
};

class Bulk_quote : public Quote {
public:
    Bulk_quote(string bn):Quote(bn){
        p = 100;
    }
    int net_price() override
    // if don't overrid the virtual function
    // then the return value is 10!
    {
        return p;
    }
    int p;
};

class Basket {
    public:
        // Basket uses synthesized default constructor and copy-control members
        void add_item(const std::shared_ptr<Quote> &sale)
        {
            items.insert(sale);
        }
        // prints the total price for each book and the overall total for all items in the basket
        double total_receipts(std::ostream&) const;
    private:
        // function to compare shared_ptrs needed by the multiset member
        static bool compare(const std::shared_ptr<Quote> &lhs,
            const std::shared_ptr<Quote> &rhs)
            {
                return lhs->isbn() < rhs->isbn();
            }
        // items is the member of the class, so it can use the private "compare" function!
        std::multiset<std::shared_ptr<Quote>, decltype(compare)*> 
            items{compare};
};

int main(int argc, char *argv[])
{
    vector<std::shared_ptr<Quote>> ql;
    for(int i = 0; i < 10; i++)
    {
        Bulk_quote a;
        ql.push_back(std::make_shared<Bulk_quote>(a));
        // if using std::make_shared<Quote>(a), then the result is exactly the Quote,
        // not the Bulk_quote instance!
        // So must using std::make_shared<Bulk_quote>(a);!
    }
    cout << std::accumulate(ql.begin(), 
        ql.end(), 
        0, 
        [](int a, std::shared_ptr<Quote> b){return a + b->net_price();}) 
    << endl;
    // The lambda using Quote, so the result must use the Quote's net_price and field num!
    return 0;
}