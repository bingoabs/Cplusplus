#include "Message.h"
#include <iostream>

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
};

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
};

void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for(auto f : lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    // the ptr saves the address, and the `swap` try
    // to reduce the data copy, so the `lhs`'s address
    // would change, that is why we need remove the `lhs` 
    // first, and then insert it!
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders)
        f->addMsg(&lhs);
    for(auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Message::addFolder(Folder* f)
{
    folders.insert(f);
    f->addMsg(this);
}

void Message::remFolder(Folder *f)
{
    folders.erase(f);
    f->remMsg(this);
}

void Message::listFolders()
{
    for(auto f : folders)
        std::cout << f->Name << std::endl;
    // if not friend, can't read the f->Name, 
    // but to friend, it works
}


void Folder::addMsg(Message *msg)
{
    msgs.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    msgs.erase(msg);
}

void Folder::listMsgs()
{
    for(auto m : msgs)
        std::cout << m->contents << std::endl;
}
// First version misses this function, it is very important!
Folder::~Folder()
{
    for(auto m : msgs)
        m->remFolder(this);
}