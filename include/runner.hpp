#pragma once
#include <deque>
#include "fire.hpp"
#include "words.hpp"
#include "graphics.h"
#include "flower.hpp"

class Runner {
public:
    Runner(Words &w);
    void setFireGroup(int, deque<shared_ptr<Fire>> &);
    void shootFireGroup(deque<shared_ptr<Fire>> &group);
private:
    Words& words_;
};