#include "Screen.h"

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}