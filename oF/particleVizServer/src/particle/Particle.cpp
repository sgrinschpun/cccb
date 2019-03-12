#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Particle.h"


Particle::Particle(shared_ptr<ParticleData>& _data): data(_data){
  ofVec2f position;
  position.set(ofGetWidth()/2, ofGetHeight()/2);
  ofVec2f velocity;
  velocity.set(0,0);
  kinematics = make_unique<Kinematics>(_data, position, velocity);
  buildModel();
}

Particle::Particle(shared_ptr<ParticleData>& _data, ofVec2f _position, ofVec2f _velocity): data(_data){
  kinematics = make_unique<Kinematics>(_data, _position, _velocity);
  buildModel();
}


void Particle::buildModel(){
    string type = data->getType();
    string name = data->getName();
    const string neutrinos[] = {"nu_e", "nu_mu", "nu_tau", "nu_ebar","nu_mubar","nu_taubar"};

    if (type == "lepton"){
      auto it = find(begin(neutrinos), end(neutrinos), name);
      if (it != end(neutrinos)) {model = make_unique<Neutrino>(data);}
      else {model = make_unique<Lepton>(data);}
    }
    else if (type == "boson") {
      model = make_unique<Boson>(data);
    }
    else if (type == "meson") {model = make_unique<Meson>(data);}
    else if (type == "baryon"){model = make_unique<Baryon>(data);}
    else if (type == "quark") {model = make_unique<Quark>(data);}
  }

void Particle::draw(){

  model->draw();

}

void Particle::drawInfo(){
  model->drawInfo();
}


void Particle::update(){
  kinematics->update();
  model->update();
}

ofPoint Particle::getPosition(){
  return kinematics->getPosition();
}

string Particle::getName(){
  return data->getName();
}
