#ifndef _Stats
#define _Stats
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
#endif
