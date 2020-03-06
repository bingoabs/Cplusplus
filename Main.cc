#include "Screen.cc"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char *argv[]){
    std::ifstream input(argv[1]);
    std::vector<std::string> strv;
    std::string line;
    while(getline(input, line))
        strv.push_back(line);
    for(auto line : strv){
        std::cout << line << std::endl;
        std::cout << "-----" << std::endl;
    }
    std::cout << "end" << std::endl;
}