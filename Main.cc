#include <utility>

class Base {
    public:
        std::size_t size() const {return n;}
    protected:
        std::size_t n;
};

class Derived : private Base {
    public:
        // maintain access levels for members related to the size of the object
        using Base::size;
    protected:
        using Base::n;
};

class Disc_quote {
    size_t  quantity;
    double discount;
public:
    std::pair<size_t, double> discount_policy() const 
    {
        return {quantity, discount};
    }
};

int main(int argc, char *argv[])
{
    return 0;
} 