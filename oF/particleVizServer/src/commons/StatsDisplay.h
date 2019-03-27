#ifndef _Stats
#define _Stats
#include <ofMain.h>
using namespace std;

struct Stats{
    int nPartScreen;
    int nPartAll;
    int fps;
    int pFrames;
    int useCPU;
    unsigned long int pMillis;
};

class StatsDisplay{
    Stats stats;
public:
    StatsDisplay();
    void update(int _nPartScreen, int _nPartAll);
    void display();
};
#endif
