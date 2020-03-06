#include "Screen.cc"
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
    // std::ifstream in(ifile);
    // std:::ofstream out;
    // out.open(ifile + ".copy");
    // if (out) // equals to !out.fail()
    // if open failed, the failbit would be set
    // so it is a better idea to check the stream status
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    std::string line = "";
    if(getline(input, line))
        output << line << " the new data" << std::endl;
    output << "end";
    return 1;
}