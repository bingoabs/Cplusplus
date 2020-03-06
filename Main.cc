#include "Screen.cc"
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    std::string line = "";
    if(getline(input, line))
        output << line << " the new data" << std::endl;
    output << "end";
    return 1;
}