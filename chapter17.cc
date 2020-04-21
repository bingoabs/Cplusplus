#include <bitset>
#include <iostream>
#include <math.h>
#include <vector>
#include <regex>
#include <string>

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

int main()
{
    string phone = 
        "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(phone); // a regex to find our pattern
    std::smatch m;
    string s;
    string fmt = "$2.$5.$7"; // reformat numbers to ddd.ddd.dddd
    // read each record from the input file
    while(std::getline(std::cin, s))
        cout << std::regex_replace(s, r, fmt) << endl;
    return 0;
    /*
    We red each record into s and hand that record to regex_replace. 
    This function finds and transforms all the matches in its input sequence.
    */
}   
