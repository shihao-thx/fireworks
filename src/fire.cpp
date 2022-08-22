#include <iostream>
using namespace std;
#include "fire.hpp"
#include "words.hpp"

Fire::Fire(int x, int y, int ly, int delay) : initx_(x), pos_y_(y), 
                    bomb_y_(ly), delay_(delay), isBomb_(false) {

}