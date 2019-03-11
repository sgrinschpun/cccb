//
//  StatsDisplay.hpp
//  cccbServer
//
//  Created by Oscar Martinez Carmona on 05/03/2019.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <ofMain.h>

using namespace std;

struct Stats{
    int nParticles;
    int fps;
    int pFrames;
    int useCPU;
    unsigned long int pMillis;
};

class StatsDisplay{
    Stats stats;
public:
    StatsDisplay();
    void update(int nPart);
    void display();
};
