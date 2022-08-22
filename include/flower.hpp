#pragma once
#include <memory>
#include <deque>
#include "fire.hpp"
#include "graphics.h"

using namespace std;

class Flower {
public:
    Flower();
    ~Flower();
    void drawFlower(deque<shared_ptr<Fire>> &group);
private:
    PIMAGE flower_image_;             
    int width_;
    color_t* buffer_;
    // every fireflower's position and it's size
    int src_r_[13] = { 35,  30,  35,  30,  30,  35,  35,  35,  35,  30,  30,  35, 30 };
	int src_x_[13] = { 35, 110, 180, 255, 325, 400, 470, 540, 615, 690, 760, 830, 905 };
	int src_y_[13] = { 35,  40,  35,  40,  35,  35,  35,  35,  35,  40,  40,  35, 30 };
    PIMAGE window_ptr_;
    int outputWidth_;
    color_t* outputBuffer_;
};