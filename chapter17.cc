#include <bitset>
#include <iostream>
#include <math.h>
#include <vector>
#include <regex>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
#include <fstream>

using std::string;
using std::endl;
using std::cout;
using std::bitset;
using std::vector;

// using namespace std::regex_contants;
// int main()
// {
//     // bitset<32> bitvec(32); // 00000100000000000000000000000000
//     // bitset<32> bv(1010101); // 101101101100101101111000000000000
//     bitset<32> bitvec(1U); // 32 bits: low-order bit is 1, remaining bits are 0;
//     bool is_set = bitvec.any(); // true, one bit is set
//     bool is_not_set = bitvec.none(); // false, one bit is set
//     bool all_set = bitvec.all(); // false, only one bit is set
//     size_t onBits = bitvec.count(); // returns 1;
//     size_t sz = bitvec.size(); // returns 32
//     bitvec.flip(); // reverses the value of all the bits in bitvec
//     bitvec.reset(); // sets all the bits to 0;
//     bitvec.set(); // sets all the bits to 1;

//     bitvec.flip(0); // reverses the value of the first bit
//     bitvec.set(bitvec.size() - 1); // turns on the last bit
//     bitvec.set(0, 0); // turns off the first bit
//     bitvec.reset(3); // turns off the ith bit
//     bitvec.test(0); // returns false because the first bit is off

//     /*
//     The subscript operator is overloaded on const .
//     The const version retusn a bool value true if the bit at the given index is on, false otherwise.
//     The nonconst version returns a special type defined by bitset that lets use manipulate the bit value 
//     at the given index position:
//     */
//     bitvec[0] = 0; // turns off the bit at position 0;
//     bitvec[31] = bitvec[0]; // set the last bit to the same value as the first bit
//     bitvec[0].flip(); // flip the value of the bit at position 0
//     ~bitvec[0]; // equivalent operation; flips the bit at position 0;
//     bool b = bitvec[0]; // convert the value of bitvec[0] to bool
//     unsigned long ulong = bitvec.to_ulong();
//     cout << " ulong = " << ulong << endl;
//     long long a = pow(2, 32) - 1;
//     bitset<32> allOne(a);
//     cout << allOne.all() << endl;
//     bitset<16> bits;
//     std::cin >> bits;
//     cout << "bits: " << bits << endl;
//     cout << (1UL << 27) << endl;
// }

// int main()
// {
//     unsigned long sum = 0U;
//     vector<int> positions = {1, 2, 3, 5, 8, 13, 21};
//     for(int p : positions)
//     {
//         sum += 1U << p;
//     }
//     bitset<22> b1(sum), b2(0U);
//     cout << b1.to_ulong() << endl;
//     for(int s = 0; s < b1.size() ; s++)
//     {
//         if (b1[s])
//         {
//             b2.set(s);
//         }
//     }
//     cout << b2.to_ulong() << endl;
// }


// template <int Size>
// struct Map {
// public:
//     Map(){};
//     bool Check(int index, bool ans){
//         if(index > Size)
//         {
//             cout << "error: index too big" << endl;
//             return false;
//         }
//         else
//             return (ques[index] == ans);
//     }
//     void Set(int index, bool ans)
//     {
//         int value = ans ? 1 : 0;
//         ques[index] = value;
//     }
// private:
//     bitset<Size> ques;
// };

// int main()
// {
//     Map<10> m;
//     cout << m.Check(1, 0) << endl;
//     cout << m.Check(1, 1) << endl;
//     cout << m.Check(100, 1) << endl;
// }

// int main()
// {
    //Part 1
    // // find the characters ei that follow a character other that c
    // string pattern("[^c]ei");
    // // we want the whole word in which our pattern appears
    // pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    // std::regex r(pattern); // construct a regex to find pattern;
    // std::smatch results; // define an object to hold the results of a search
    // // define a string that has text that does and doesn't match pattern
    // string test_str = "receipt freind theif receive";
    // // use r to find a match to pattern in test_str
    // if (std::regex_search(test_str, results, r)) // if there is a match
    //     cout << results.str() << endl; // print the matching word
    
    //Part 2
    // one or more alphanumberic characters followed by a '.' followed by "cpp" or "cxx" or "cc"
    // std::smatch results;
    // std::regex r("[[:alpha:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
    // string filename;
    // while(std::cin >> filename)
    //     if (std::regex_search(filename, results, r))
    //         cout << results.str() << endl; // print the current match

    // Part 3
    // try {
    //     // error: missing close bracket after alnum; the constructor will throw
    //     std::regex r("[[:alpha:]+\\.(cpp|cxx|cc)$", std::regex::icase);
    // } catch (std::regex_error e)
    // {
    //     cout << e.what() << "\ncode: " << e.code() << endl;
    // }

    // Part 4
    // std::regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
    // // std::smatch results; // will match a string input sequence, but not char*
    // // if(std::regex_search("myfile.cc", results, r)) // error: char* input
    // //     cout << results.str() << endl;
    // std::cmatch results;
    // if(std::regex_search("myfile.cc", results, r)) // works, using cmatch
    //     cout << results.str() << endl;
    
//     // Part 5
//     // find the characters ei that follow a character other that c
//     string pattern("[^c]ei");
//     // we want the whole word in which our pattern appears
//     pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//     std::regex r(pattern, std::regex::icase); // we'll ignore case in doing the match
//     // it will repeatedly call regex_search to find all matches in file
//     string file = "testest";
//     // for: init, then cout the expression, then run the main part
//     for(std::sregex_iterator it(file.begin(), file.end(), r), end_it; 
//     it != end_it; ++it)
//         cout << it->str() << endl; // matched word
// }

// int main()
// {
//     string phone = 
//         "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
//     std::regex r(phone); // a regex to find our pattern
//     std::smatch m;
//     string s;
//     string fmt = "$2.$5.$7"; // reformat numbers to ddd.ddd.dddd
//     // read each record from the input file
//     while(std::getline(std::cin, s))
//         cout << std::regex_replace(s, r, fmt) << endl;
//     return 0;
//     /*
//     We red each record into s and hand that record to regex_replace. 
//     This function finds and transforms all the matches in its input sequence.
//     */
// }   


// vector<unsigned> bad_randVec()
// {
//     std::default_random_engine e;
//     std::uniform_int_distribution<unsigned> u(0, 9);
//     vector<unsigned> ret;
//     for(size_t i = 0; i < 100; ++i)
//         ret.push_back(u(e));
//     return ret;
// }
// vector<unsigned> goo_randVec()
// {
//     static std::default_random_engine e;
//     static std::uniform_int_distribution<unsigned> u(0, 9);
//     vector<unsigned> ret;
//     for(size_t i = 0; i < 100; ++i)
//     {
//         ret.push_back(u(e));
//     }
//     return ret;
// }

// int main()
// {
//     std::default_random_engine e;

//     for(size_t i = 0; i < 10; ++i)
//         // e() "call" the object to generate the next random number
//         cout << e() << " ";
//     cout << endl;
//     std::uniform_int_distribution<unsigned> u(0, 9);
//     for(size_t i = 0; i < 10; i++)
//         // set the u to the random source
//         // every call will return the value in the range 
//         cout << u(e) << " ";
//     cout << endl;
//     // the results are same!
//     for(auto i = 0; i < 2; i++)
//     {
//         vector<unsigned> a = bad_randVec();
//         for(auto i : a)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }

//     std::default_random_engine e1; // using default seed
//     std::default_random_engine e2(2147483646);
//     std::default_random_engine e3; // using default seed
//     e3.seed(32767); // call seed to set a new seed
//     std::default_random_engine e4(32767); // set the seed to 32767
//     for(size_t i = 0; i != 100; ++i)
//     {
//         if (e1() == e2())
//             cout << "unseeded match at iteration: " << i << endl;
//         if (e3() == e4())
//             cout << "seeded differs at iteration: " << i << endl;
//     }
//     std::default_random_engine e5(time(0)); // using the timestamp as the seed
// }


// int main()
// {
//     std::default_random_engine e; // generate unsigned integer
//     std::uniform_real_distribution<double> u(0, 1);
//     for(size_t i = 0; i < 10; ++i)
//     {
//         cout << u(e) << " ";
//     }
// }

// int main()
// {
//     cout << "default bool values: " << true << " " << false
//         << "\nalpha bool values: " << std::boolalpha // << std::noboolalpha
//         << true << " " << false << endl;
//     cout << std::showbase;
//     cout << "default: " << 20 << " " << 1024 << endl;
//     cout << "octal: " << std::oct << 20 << " " << 1024 << endl;
//     cout << "hex: " << std::hex << 20 << " " << 1024 << endl;
//     cout << "decimal: " << std::dec << 20 << " " << 1024 << endl;
//     cout << std::noshowbase;
// }

//     std::normal_distribution<double> n(4, 1.5);
//     vector<unsigned> vals(9);
//     for(size_t i = 0; i != 200; ++i)
//     {
//         unsigned v = lround(n(e));
//         if(v < vals.size())
//             ++vals[v];
//     }
//     for(size_t j = 0; j != vals.size(); ++j)
//         cout << j << ": " << string(vals[j], '*') << endl;
// }

// bool play(bool input)
// {
//     return input;
// }
// int main()
// {
//     string resp;
//     std::default_random_engine e; // e has state, so it must be outside the loop!
//     std::bernoulli_distribution b; // 50 / 50 odds by default
//     do {
//         bool first = b(e); // if true, the program will go first
//         cout << (first ? " We go first"
//             :"You get to go first") << endl;
//         // play the game passing the indicator of who goes first
//         cout << ((play(first)) ? "sorry, you lost"
//             : "congrats, you won") << endl;
//         cout << "play again? Enter 'yes' or 'no'" << endl;
//     } while(std::cin >> resp && resp[0] == 'y');
// }

// int main()
// {
//     cout << std::hex << std::uppercase << time(0) << endl;
//     cout << std::dec;
//     cout << sqrt(2.0) << endl;
// }
/*
// int main()
// {
//     int ch; // use an int, not a char to hold the return from get()
//     // loop to read and write all the data in th input
//     while((ch = std::cin.get()) != EOF)
//         cout.put(ch);
// }
*/
// int main()
// {
    // Part 1:
    // char clist[20];
    // std::ifstream  inf("temp.md");
    // inf.getline(clist, 17, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // inf.getline(clist, 17, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // inf.getline(clist, 17, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;

    // char clist[20];
    // std::ifstream  inf("temp.md");
    // inf.getline(clist, 2, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // // clear will keep on reading the current line following the readed characters
    // inf.clear();
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // inf.getline(clist, 2, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // inf.clear();
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // inf.getline(clist, 2, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;

    // char clist[10];
    // std::ifstream  inf("temp.md");
    // // if the clist size less than the parameter, 
    // // the getlin still inserts the data!
    // // It can break the other data!
    // inf.getline(clist, 15, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // inf.getline(clist, 2, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
    // inf.getline(clist, 12, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;


    // char clist[20];
    // std::ifstream  inf("temp.md");
    // inf.clear(std::ios_base::failbit);
    // // if the iostream is in failbit, it can't use the getline to read the data!
    // inf.getline(clist, 2, '\n');
    // cout << std::boolalpha << (inf.rdstate() == std::ios_base::failbit) << endl;
    // cout << inf.gcount() << endl;
    // cout << clist << endl;
// }

// #include <iomanip>

// int main()
// {
//     cout << "Precision: " << cout.precision()
//         << ", Value: " << sqrt(2.0) << endl;
//     cout.precision(12);
//     cout << "Precision: " << cout.precision()
//         << ", Value: " << sqrt(2.0) << endl;
//     cout << std::setprecision(3);
//     cout << "Precision: " << cout.precision()
//         << ", Value: " << sqrt(2.0) << endl;

// }

// int main()
// {
//     int i = -16;
//     double d = 3.1415926;
//     cout << "i: " << std::setw(12) << i << "next col" << '\n'
//         << "d: " << std::setw(12) << d << "next col" << '\n';
//     cout << std::left 
//         << "i: " << std::setw(12) << i << "next col" << '\n'
//         << "d: " << std::setw(12) << d << "next col" << '\n'
//         << std::right;
//     cout << std::right
//         << "i: " << std::setw(12) << i << "next col" << '\n'
//         << "d: " << std::setw(12) << d << "next col" << '\n';
//     cout << std::internal 
//         << "i: " << std::setw(12) << i << "next col" << '\n'
//         << "d: " << std::setw(12) << d << "next col" << '\n';
//     cout << std::setfill('#')
//         << "i: " << std::setw(12) << i << "next col" << '\n'
//         << "d: " << std::setw(12) << d << "next col" << '\n'
//         << std::setfill(' ');
// }

// template <typename T>
// class Blob {
//     Blob(std::initializer_list<T>);
//     std::shared_ptr<std::vector<T>> data;
// };

// template <typename T>
// Blob<T>::Blob(std::initializer_list<T> il) 
//     try : data(std::make_shared<std::vector<T>>(il))
//     {

//     } catch(const std::bad_alloc &e) {
//         // handle_out_of_memory(e);
//     }

// int main()
// {
//     void (*pf1)(int) noexcept = recoup;
//     void (*pf2)(int) = recoup;

//     pf1 = alloc; // error, alloc may raise error, so doesn't match the declare
//     pf2 = alloc;
// }

// class Base {
//     public:
//         virtual double f1(double) noexcept;
//         virtual int f2() noexcept(false);
//         virtual void f3();
// };

// class Defived : public Base {
//     public:
//         double f1(double); // error, Base::f1 don't raise error
//         int f2() noexcept(false); // right; same as the declare in Base
//         void f3() noexcept;
// };

class out_of_stock: public std::runtime_error
{
    public:
        explicit out_of_stock(const std::string &s):
            std::runtime_error(s){}
};

class isbn_mismatch: public std::logic_error {
    public:
        explicit isbn_mismatch(const std::string &s):
            std::logic_error(s){}
        isbn_mismatch(const std::string &s,
            const std::string &lhs, const std::string &rhs):
            std::logic_error(s), left(lhs), right(rhs){}
        const std::string left, right;
};

int main()
{
    // usage
    try {

        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    } catch (const isbn_mismatch &e)
    {
        std::cerr << e.what() << ": left isbn(" << e.left
            <<") right isbn(" << e.right << ")" << endl;
    }
}