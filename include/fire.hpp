#pragma once
#include <utility>
using namespace std;
#include "words.hpp"

class Fire {
friend class Runuer;
public:
    enum { INITY=800 };
    Fire(int, int, int, int);

    inline int GetDelay() { return delay_; }
    inline int GetInitX() { return initx_; }
    inline int GetPosY() { return pos_y_; }
    inline int GetBombY() { return bomb_y_; }
    inline void DownDelay() { delay_--; }
    inline void UpY() { pos_y_-=1; }
    inline void Bomb() { isBomb_=true; }
    inline bool GetBomb() { return isBomb_; }
private:
    int initx_;
    int pos_y_;
    int bomb_y_;
    int delay_; 
    bool isBomb_; 
};