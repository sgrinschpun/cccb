#ifndef _AudioVisualManager
#define _AudioVisualManager

#include "VisualManager.h"
#include "PhenomenaCMD.h"

class AudioVisualManager{
    VisualManager vManager;
public:
    AudioVisualManager();
    void update(PhenomenaCMD phenoCMD);
    void draw();
};
#endif
