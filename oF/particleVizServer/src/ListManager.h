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


  float padding{50};

public:
  std::map <int, shared_ptr<Particle>> particleMap;
  std::mutex _mtx;
  // std::mutex, std::unique_lock
  void updateMap(PhenomenaCMD phenoCMD);
  bool isEmpty();
  bool isScreenEmpty();
  void lock(){this->_mtx.lock();};
  void unlock(){this->_mtx.unlock();};
  bool particleIsOutOfBounds(const shared_ptr<Particle>& _particle);
  int numberOnScreen();

  void update();
  void draw();

  ListManager();
};
#endif
