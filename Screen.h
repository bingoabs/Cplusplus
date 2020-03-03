#include <string>
#include <vector>
#include <iostream>

class Screen {
    // friend class Window_mgt; // Set the class to be a friend
    // friend Window_mgr::clear(ScreenIndex); // Set the member of some class to be friend;
    public:
        typedef std::string::size_type pos;
        // using pos = std::string::size_type;
        Screen() = default;
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, 'c') {};
        Screen(pos ht, pos wd, char c): height(ht), width(wd),
        contents(ht * wd, c) {};
        char get() const {// implict inline
            return contents[cursor];
        }
        inline char get(pos ht, pos wd) const; // explicit inline
        Screen &move(pos r, pos c);
        void some_member() const;
        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &display(std::ostream &os){
            os << "non-const" << std::endl;
            do_display(os);
            return *this;
        }
        const Screen &display(std::ostream &os) const {
            os << std::endl << "const" << std::endl;
            do_display(os);
            return *this;
        }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        mutable size_t access_ctr;
        void do_display(std::ostream &os) const {
            os << contents;
        }
};
// the best choice is to put the inline function in the `head file`
inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}
// Despite it is a const function, but we can change the value of the memeber
// if the member is decoreated with `mutable`
void Screen::some_member() const
{
    ++access_ctr;
    // other thing if required
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

class Window_mgr {
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};
};
