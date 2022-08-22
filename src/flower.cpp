#include <iostream>
#include "flower.hpp"
#include <math.h>

using namespace std;
extern PIMAGE bg;

Flower::Flower() : flower_image_(newimage()), window_ptr_(newimage(getwidth(), getheight())), 
                outputWidth_(getwidth(window_ptr_)) {
    if (getimage(flower_image_, "image\\flower.jpg")!= grOk) {
      cout<< "fail to load the image!" << endl;
      exit(-1);
    }

    buffer_=(color_t*) getbuffer(flower_image_);
    width_=getwidth(flower_image_);
    outputBuffer_ = (color_t*)getbuffer(window_ptr_);
}

void Flower::drawFlower(deque<shared_ptr<Fire>> &group) {
    int tempRand =rand()%13;

    int rx, ry, r=0;
    const color_t* data = buffer_;
    
    while(r<=src_r_[tempRand]) {
        for(auto& a : group) {
            for(double deg=0.0; deg<=6.28; deg+=0.01) {
                rx=r * cos(deg);
                ry=r * sin(deg);
                outputBuffer_[(a->GetBombY()+ry)*outputWidth_+(a->GetInitX()+rx)] 
                        = data[(src_y_[tempRand]+ry)*width_+(src_x_[tempRand]+rx)];
            }
        }
        putimage(0, 0, window_ptr_);
        r += 1;
        if(r<5) { 
            Sleep(1);
        } else if(r<10) {
            Sleep(2);
        } else if(r<15) { 
            Sleep(4);
        } else if(r<20) {
            Sleep(8);
        } else if(r<25) { 
            Sleep(16);
        } else if(r<30){
            Sleep(32); 
        } else {
            Sleep(64);
        }
    }
    
    cleardevice();
} 

Flower::~Flower() {
    delimage(flower_image_);
    delimage(window_ptr_);
}