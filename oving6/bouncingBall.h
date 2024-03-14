#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"


void bouncingBall();

struct Config {
    int velocity;
    int colorUp; 
    int colorDown; 
    map<int, TDT4102::Color> colorMap; 
    Config();
    friend std::istream& operator>>(istream& is, Config& cfg);
};

