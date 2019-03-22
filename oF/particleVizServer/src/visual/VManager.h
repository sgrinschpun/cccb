#ifndef _VManager
#define _VManager

#include "ofMain.h"
#include "CallToActionController.h"
#include "Particle.h"

class VManager{
private:
  shared_ptr<map<int, shared_ptr<Particle>>> particleMap;
  typedef map<int, shared_ptr<Particle>>::iterator particleIterator;

  ofFbo rgbaFbo;
  float fboWidth;
  float fboHeight;
  void setupFbo();
  void drawFbo();
  static float fadeAmnt;

  unique_ptr <CallToActionController> callToAction;

public:
  void update();
  void draw();

  VManager(shared_ptr<map <int, shared_ptr<Particle>>> _particleMap);
};
#endif
