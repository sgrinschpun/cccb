#ifndef _AudioVisualManager
#define _AudioVisualManager

#include "VisualManager.h"
#include "PhenomenaCMD.h"

class AudioVisualManager{
    VisualManager vManager;
public:
    AudioVisualManager();
    void updateMap(PhenomenaCMD phenoCMD);
    void update();
    void draw();
};
#endif
