#ifndef _Particle //
#define _Particle //
#include "ofMain.h"
#include "ParticleData.h"
#include "Model.h"
#include "Kinematics.h"
#include "Lepton.h"
#include "Boson.h"
#include "Meson.h"
#include "Baryon.h"
#include "Quark.h"
#include "Neutrino.h"

class Particle {
  private:
  shared_ptr<ParticleData> data;
  unique_ptr<Model> model;
  unique_ptr<Kinematics> kinematics;

  void buildModel();

  public:
  void update();
  void draw();

  ofPoint getPosition();

  Particle(shared_ptr<ParticleData>& _data);
  Particle(shared_ptr<ParticleData>& _data, ofPoint _position, ofVec3f _velocity);
  ~Particle() {
    kinematics.reset();
    model.reset();
    data.reset();
  }

};
#endif
