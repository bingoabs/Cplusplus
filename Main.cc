#include <iostream>
#include "Message.cc"

// class strVec
// {
//     public:
//         strVec& operator=(strVec &&rhs) noexcept 
//         {
//             if(this != &rhs)
//             {
//                 free();
//                 elements = rhs.elements;
//                 first_free = rhs.first_free;
//                 cap = rhs.cap;
//                 rhs.elements = rhs.first_free = rhs.cap = nullptr;
//             }
//         }
// };

int main(int argc, char *argv[])
{
    Message m1("MsgOne"), m2("MsgTwo");
    Folder f1("Folder1"), f2("Folder2");
    m1.addFolder(&f1);
    m1.addFolder(&f2);
    m2.addFolder(&f2);
    std::cout << "-------" << std::endl;
    m1.listFolders();
    std::cout << "-------" << std::endl;
    m2.listFolders();
    std::cout << "-------" << std::endl;
    f1.listMsgs();
    std::cout << "-------" << std::endl;
    f2.listMsgs();
    std::cout << "-------" << std::endl;
    return 0;
} 