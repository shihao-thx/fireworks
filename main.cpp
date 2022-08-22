#include <iostream>
#include <memory>
#include <windows.h>
#include <ctime>
#include "fire.hpp"
#include "graphics.h"
#include "mmsystem.h"
#include "runner.hpp"
#include "flower.hpp"

#pragma comment(lib,"winmm.lib")

using namespace std;
using namespace ege;

PIMAGE bg;
PIMAGE bg_helper;

int main() {
	setcaption("Happy birthday to you.");
	initgraph(800, 800, 0);

    mciSendString("play music/happybirthday.mp3", 0, 0, 0);
	Sleep(11000);

	srand((unsigned)time(NULL));

	// need to specify the num of words showing
	Words w1(4);
    Runner run(w1);
	int times = 7;
	while(times) {
		for(int i=0; i<w1.Getnum(); i++) {
		// 1 represents the first word
			deque<shared_ptr<Fire>> fires1;
			Flower f;
			run.setFireGroup(i,fires1);
			run.shootFireGroup(fires1);
			f.drawFlower(fires1);
		}
		times--;
	}
	
	getch();							
 
	closegraph();				
	
	return 0;
}