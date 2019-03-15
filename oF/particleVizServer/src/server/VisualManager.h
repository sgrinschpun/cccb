#ifndef _VisualManager
#define _VisualManager
#include <map>
#include "PhenomenaCMD.h"
#include "Particle.h"
#include "ParticleData.h"
#include <memory>
#include "StatsDisplay.h"
#include "CallToActionController.h"
using namespace std;

class VisualManager{
  map <int, shared_ptr<Particle> > particleMap;
  map <int, shared_ptr<Particle> > ::iterator particleIt;
  StatsDisplay sDisplay;
  unique_ptr <CallToActionController> callToAction;

  static float fadeAmnt;

public:
  VisualManager();
  void updateMap(PhenomenaCMD phenoCMD);
  void update();
  void draw();

  ofFbo rgbaFbo;
  float fboWidth;
  float fboHeight;
  void setupFbo();
  void drawFbo();
};
#endif
