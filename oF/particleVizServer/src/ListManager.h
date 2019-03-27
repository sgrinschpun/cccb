#ifndef _ListManager
#define _ListManager

#include "PhenomenaCMD.h"
#include "Particle.h"
#include "ParticleData.h"
#include <map>
#include <mutex>

class ListManager{

private:
  void cleanupList();
  bool particleIsOutOfBounds(const shared_ptr<Particle>& _particle);
  float padding{50};

public:
  std::map <int, shared_ptr<Particle>> particleMap;
  std::mutex _mtx;
  // std::mutex, std::unique_lock
  void updateMap(PhenomenaCMD phenoCMD);
  bool listIsEmpty();
  void lock(){this->_mtx.lock();};
  void unlock(){this->_mtx.unlock();};

  void update();
  void draw();

  ListManager();
};
#endif
