#include "CallToActionDisplay.h"

ofxCenteredTrueTypeFont CallToActionDisplay::myFont;

void CallToActionDisplay::setupFont(){
  if (!myFont.isLoaded()){
    myFont.load("Lato-Regular.ttf",25);
  }
}

void CallToActionDisplay::setParticleList(){
  shared_ptr<ParticleData> quark = make_shared<ParticleData>(-1,1,"topCTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> higgs = make_shared<ParticleData>(-1,1,"higgsCTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> w = make_shared<ParticleData>(-1,1,"WCTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> tau = make_shared<ParticleData>(-1,1,"tauCTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> pi0 = make_shared<ParticleData>(-1,1,"pi0CTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> jpsi = make_shared<ParticleData>(-1,1,"jpsiCTA",1.,1.,"calltoaction",1.);
  shared_ptr<ParticleData> omega = make_shared<ParticleData>(-1,1,"omegaCTA",1.,1.,"calltoaction",1.);
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
  setText("CREATE A PARTICLE");
  ofPopMatrix();
}

void CallToActionDisplay::setText(const string &text){
  ofSetColor(255,255,255);
  ofSetLineWidth(0);
  myFont.drawCenteredBoundingBox(text, 0, 0, padding);
  myFont.drawStringCentered(text, 0, 0);
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
