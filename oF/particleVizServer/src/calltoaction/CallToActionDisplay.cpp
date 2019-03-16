#include "CallToActionDisplay.h"

ofTrueTypeFont CallToActionDisplay::myFont;

void CallToActionDisplay::setupFont(){
  if (!myFont.isLoaded()){
    myFont.load("Lato-Regular.ttf",30);
  }
}

void CallToActionDisplay::setParticleList(){
  shared_ptr<ParticleData> quark = make_shared<ParticleData>(-1,1,"t",1.,1.,"quark",1.);
  shared_ptr<ParticleData> higgs = make_shared<ParticleData>(-1,1,"h0(H_1)",1.,1.,"boson",1.);
  shared_ptr<ParticleData> w = make_shared<ParticleData>(-1,1,"W+",1.,1.,"boson",1.);
  shared_ptr<ParticleData> tau = make_shared<ParticleData>(-1,1,"tau-",1.,1.,"lepton",1.);
  shared_ptr<ParticleData> pi0 = make_shared<ParticleData>(-1,1,"pi0",1.,1.,"meson",1.);
  shared_ptr<ParticleData> jpsi = make_shared<ParticleData>(-1,1,"J/psi",1.,1.,"meson",1.);
  shared_ptr<ParticleData> omega = make_shared<ParticleData>(-1,1,"Omega_b-",1.,1.,"baryon",1.);
  particleList.push_back(make_shared<Particle>(quark));
  particleList.push_back(make_shared<Particle>(higgs));
  particleList.push_back(make_shared<Particle>(w));
  particleList.push_back(make_shared<Particle>(tau));
  particleList.push_back(make_shared<Particle>(pi0));
  particleList.push_back(make_shared<Particle>(jpsi));
  particleList.push_back(make_shared<Particle>(omega));
}

CallToActionDisplay::CallToActionDisplay(){
  setupFont();
  setParticleList();
  selectedParticle = 0;
}

void CallToActionDisplay::draw(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  particleList[selectedParticle]->draw();
  myFont.drawString("Enter the Dragon",0,0);
  ofPopMatrix();
}

void CallToActionDisplay::update(){
  particleList[selectedParticle]->update();
}

void CallToActionDisplay::setNew(){
  if (selectedParticle==particleList.size()){
    selectedParticle = 0;
  }
  else {selectedParticle +=1;}
}
