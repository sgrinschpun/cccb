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
#include "CallToActionModel.h"

class Particle {
  private:
  shared_ptr<ParticleData> data;
  unique_ptr<Model> model;
  unique_ptr<Kinematics> kinematics;
  void buildModel();

  public:

  void update();
  void draw();
  void drawInfo();

  ofVec2f getPosition();
  string getName();

  Particle(shared_ptr<ParticleData>& _data);
  Particle(shared_ptr<ParticleData>& _data, ofVec2f _position, ofVec2f _velocity);
  ~Particle() {
    kinematics.reset();
    model.reset();
    data.reset();
  }

};
#endif
