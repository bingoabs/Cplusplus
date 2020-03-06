#include "Screen.cc"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char *argv[]){
    std::ofstream out("file1");// implict using `out` model
    std::ofstream out2("file1", std::ofstream::out);// implict `trunc` the file
    std::ofstream out3("file1", std::ofstream::out | std::ofstream::trunc); // explict using `trunc`
    std::ofstream app("file2", std::ofstream::app); // `append` implict using `out` model
    std::ofstream app2("file2", std::ofstream::out | std::ofstream::app); // explicit using `out` and `app`
}