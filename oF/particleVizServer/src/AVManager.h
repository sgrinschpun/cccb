#ifndef _AVManager
#define _AVManager

#include "PhenomenaCMD.h"
#include "Particle.h"
#include "ParticleData.h"
#include "VManager.h"


class AVManager{

private:
  typedef map<int, shared_ptr<Particle>>::iterator particleIterator;
  particleIterator particleIt;
  unique_ptr<VManager> vizManager;

public:
  shared_ptr<map <int, shared_ptr<Particle>>> particleMap;
  void updateMap(PhenomenaCMD phenoCMD);

  void update();
  void draw();

  AVManager();
};
#endif
