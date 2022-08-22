#pragma once
#include <vector>
#include <utility>
#include "graphics.h"

using namespace std;

class Words {
public:
    Words(int x);
    inline vector<pair<int,int>> const& getWord(int x) { return words_[x]; }
    void putImage(int x, int y, int srcX, int srcY);
    void getImage(int x, int y);
    inline int Getnum() { return num_; }
    ~Words();
private:
    vector<vector<pair<int,int>>> words_;
    int num_;
    PIMAGE img_;

    // 生
    const vector<pair<int,int>> word3_ = {{3,1},{5,1},{3,2},{5,2},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{1,4},{5,4},
    {5,5},{3,6},{4,6},{5,6},{6,6},{7,6},{5,7},{5,8},{1,9},{2,9},{3,9},{4,9},{5,9},{6,9},{7,9},{8,9},{9,9}};
    // 日
    const vector<pair<int,int>> word4_ = {{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{2,2},{7,2},{2,3},{7,3},{2,4},{7,4},{2,5},
    {3,5},{4,5},{5,5},{6,5},{7,5},{2,6},{7,6},{2,7},{7,7},{2,8},{7,8},{2,9},{3,9},{4,9},{5,9},{6,9},{7,9}};
    // 快
    const vector<pair<int,int>> word5_ = {{2,1},{6,1},{2,2},{4,2},{5,2},{6,2},{7,2},{8,2},{2,3},{6,3},{8,3},{1,4},{2,4},
    {3,4},{6,4},{8,4},{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{8,5},{9,5},{2,6},{6,6},{2,7},{5,7},{7,7},{2,8},{4,8},
    {8,8},{2,9},{3,9},{9,9}};
    // 乐
    const vector<pair<int,int>> word6_ = {{7,1},{2,2},{3,2},{4,2},{5,2},{6,2},{2,3},{5,3},{2,4},{5,4},{2,5},{3,5},{4,5},
    {5,5},{6,5},{7,5},{5,6},{3,7},{5,7},{6,7},{2,8},{4,8},{5,8},{7,8},{5,9},{8,9}};
};