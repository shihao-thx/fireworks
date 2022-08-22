#include <iostream>
#include <memory>
#include "graphics.h"
#include "words.hpp"

using namespace std;

extern PIMAGE bg;
extern PIMAGE bg_helper;

Words::Words(int x) : num_(x), img_(newimage()) {
   if (getimage(img_, "image\\shoot.jpg")!= grOk) {
      cout<< "fail to load the image!" << endl;
      exit(-1);
   }

   words_.push_back(word3_);
   words_.push_back(word4_);
   words_.push_back(word5_);
   words_.push_back(word6_);
}

void Words::putImage(int x, int y, int srcX, int srcY) {
   putimage(x, y, 10, 20, img_, srcX, srcY);
}

Words::~Words() {
   delimage(img_);
}