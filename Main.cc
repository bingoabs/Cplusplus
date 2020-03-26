#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
#include <iterator> // for the istream_iterator
#include <forward_list>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include <istream>
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;
using std::list;
using std::stack;
using std::forward_list;
using std::map;
using std::set;
using std::multiset;
using std::shared_ptr;
using std::unique_ptr;
using std::allocator;
using std::ifstream;

class TreeNode {
    private:
        string value;
        int cout;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode(string v):value(v),left(nullptr),right(nullptr){}
        TreeNode(const TreeNode&);
        void Set(TreeNode& left, TreeNode& right);
        TreeNode& operator=(const TreeNode&);
        ~TreeNode();
};

TreeNode::~TreeNode(){
    if (left != nullptr)
        delete left;
    if (right != nullptr)
        delete right;
}
// The key point to decide the copy
TreeNode& TreeNode::operator=(const TreeNode &rhs){
    if (rhs.left != nullptr)
        left = new TreeNode(*rhs.left);
    if (rhs.right != nullptr)
        right = new TreeNode(*rhs.right);
    cout = rhs.cout;
    value = rhs.value;
    return *this;
}

TreeNode::TreeNode(const TreeNode &s)
{
    // copy the ptr, the object are same
    // left = s.left;
    // right = s.right;
    // value = s.value;
    // cout = s.cout;

    // or operator= to copy the object, not the ptr
    if (s.left != nullptr)
    {
        std::cout << "copy left: " << s.value << endl;
        left = new TreeNode(*s.left);
    }
    else
    {
        left = nullptr;
    }
    
    if (s.right != nullptr)
    {
        std::cout << "copy right: " << s.value << endl;
        right = new TreeNode(*s.right);
    }
    else
    {
        right = nullptr;
    }
    
    value = s.value;
    cout = s.cout;
}

void TreeNode::Set(TreeNode& l, TreeNode& r){
    std::cout << "begin Set left" << endl;
    left = new TreeNode(l);
    std::cout << "begin Set right" << endl;
    right = new TreeNode(r);
    std::cout << "finish Set" << endl;
}

int main(int argc, char *argv[])
{
    TreeNode root("root");
    std::cout << "-----" << endl;
    TreeNode first("first"), second("second");
    std::cout << "-----" << endl;
    TreeNode first1("first1"), first2("first2");
    first.Set(first1, first2);
    std::cout << "-----" << endl;
    TreeNode second1("second1"), second2("second2");
    second.Set(second1, second2);
    std::cout << "-----" << endl;
    root.Set(first, second);
    std::cout << "-----" << endl;
    TreeNode rc = root;
    cout << "here" << endl;
    return 0;
} 