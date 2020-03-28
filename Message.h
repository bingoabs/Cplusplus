#include <string>
#include <set>

class Message;
class Folder{
    friend class Message;
public:
    Folder(const std::string name = ""):Name(name){}
    void addMsg(Message*);
    void remMsg(Message*);
    void listMsgs();
    ~Folder();
private:
    std::string Name;
    std::set<Message*> msgs;
};

class Message {
    friend class Folder;
public:
    explicit Message(const std::string &str=""):
        contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void swap(Message&, Message&);
    void addFolder(Folder*);
    void remFolder(Folder*);
    void listFolders();
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};
