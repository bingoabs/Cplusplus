#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <array>
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
// using namespace std::placeholders;
// we can directly use the names in this namespace!


int main(int argc, char *argv[]){
    vector<int> loopNums = {256, 512, 1000, 1048};
    for(int maxIndex : loopNums)
    {
        cout << "Max Index value is: " << maxIndex << endl;
        vector<string> records;
        records.reserve(1024);
        cout << "begin " << "size: " << records.size() << " " << "capacity: " << records.capacity() << endl;
        for(int index = 0; index < maxIndex; ++index)
            records.push_back("records");
        cout << "after " << "size: " << records.size() << " " << "capacity: " << records.capacity() << endl;
        records.resize(records.size() + records.size()/2);
        cout << "end " << "size: " << records.size() << " " << "capacity: " << records.capacity() << endl;
        cout << endl << endl;
    }
}