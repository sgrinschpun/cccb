#ifndef _ListManager
#define _ListManager

#include "PhenomenaCMD.h"
#include "Particle.h"
#include "ParticleData.h"


class ListManager{

private:

public:
  map <int, shared_ptr<Particle>> particleMap;
  map <int, shared_ptr<Particle> > ::iterator particleIt;

  void updateMap(PhenomenaCMD phenoCMD);
  bool listIsEmpty();

  void update();
  void draw();

  ListManager();
};
#endif
