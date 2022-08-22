#include <iostream>
#include <memory>
#include <utility>
#include <windows.h>
#include "runner.hpp"
#include "fire.hpp"

using namespace std;

extern  PIMAGE bg;

Runner::Runner(Words& w) : words_(w){
    
}

void Runner::setFireGroup(int x, deque<shared_ptr<Fire>> &group) {
    int init_x, lowest_y, delay, flag=0, basic;
    shared_ptr<Fire> tempPtr;
    if(x!=1) { 
        for(auto const& a : words_.getWord(x)) {
            if(flag==0) { basic= a.second; flag++; }
            init_x = a.first * 70 + 90; 
            lowest_y = a.second * 70;
            delay = (a.second-basic)*70; // △t=△s/v 90/2; 70 / upV
            tempPtr = make_shared<Fire>(init_x, Fire::INITY, lowest_y, delay);
            group.push_back(tempPtr);
        }  
    } else { 
        for(auto const& a : words_.getWord(x)) {
            if(flag==0) { basic= a.second; flag++; }
            init_x = a.first * 70 + 90; 
            lowest_y = a.second * 60;
            delay = (a.second-basic)*60; // △t=△s/v 90/2
            tempPtr = make_shared<Fire>(init_x, Fire::INITY, lowest_y, delay);
            group.push_back(tempPtr);
        } 
    }
}

void Runner::shootFireGroup(deque<shared_ptr<Fire>> &group) {
    while(!group.front()->GetBomb()) {
        for(int i=0; i<group.size(); i++) {
            if(group[i]->GetDelay() <= 0 && group[i]->GetPosY() > group[i]->GetBombY()) {
                words_.putImage(group[i]->GetInitX(), group[i]->GetPosY(), 0, 0);
                group[i]->UpY();
            } else if(group[i]->GetPosY() <= group[i]->GetBombY()) {
                group[i]->Bomb();
            } else if(group[i]->GetDelay() > 0) {
                group[i]->DownDelay();
            }
        }

        Sleep(1);
        cleardevice();
    }
}