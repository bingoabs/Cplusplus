#include "Chapter6.h"
#include <iostream>

using std::endl;
using std::cout;
using std::string;

// int main(int argc, char *argv[])
int main(int argc, char **argv){
    cout << argc << endl;
    int index = 1;
    string resp = "awerewr";
    cout << resp << endl;
    while(index <= argc){
        cout << argv[index++] << endl;
        //resp += argv[index++];
        cout << index << endl;
    }
    // so werid the resp don't print....
    // I don't know why
    cout << resp;
    cout << endl;
    return 0;
}