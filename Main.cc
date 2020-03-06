#include "Screen.cc"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char *argv[]){
    std::ifstream input(argv[1]);
    std::string line;
    while(getline(input, line))
    {
        for(char &c : line)
        {
            if(c != ' ')
            {
                std::cout << c;
            } else {
                std::cout << std::endl << "next word: " << std::endl;
            }
        }
    }
    // while(input >> c) // >> would ignore the space, \t etc..
    // {
    //     if(c != space)
    //         std::cout << c;
    //     else
    //     {
    //         std::cout << std::endl << "next word: " << std::endl;
    //     }   
    // }
}