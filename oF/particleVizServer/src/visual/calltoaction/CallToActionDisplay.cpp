#include "CallToActionDisplay.h"
#include "Parameters.h"

ofxXmlSettings CallToActionDisplay::xmlTexts=ofxXmlSettings("texts.xml");

void CallToActionDisplay::setParticleList(){
  shared_ptr<ParticleData> quark = make_shared<ParticleData>(-1,1,"topCTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> higgs = make_shared<ParticleData>(-1,1,"higgsCTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> w = make_shared<ParticleData>(-1,1,"WCTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> tau = make_shared<ParticleData>(-1,1,"tauCTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> pi0 = make_shared<ParticleData>(-1,1,"pi0CTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> jpsi = make_shared<ParticleData>(-1,1,"jpsiCTA",1.,1.,"calltoaction",1.,"");
  shared_ptr<ParticleData> omega = make_shared<ParticleData>(-1,1,"omegaCTA",1.,1.,"calltoaction",1.,"");
  particleList.push_back(make_shared<Particle>(quark));
  particleList.push_back(make_shared<Particle>(higgs));
  particleList.push_back(make_shared<Particle>(w));
  particleList.push_back(make_shared<Particle>(tau));
  particleList.push_back(make_shared<Particle>(pi0));
  particleList.push_back(make_shared<Particle>(jpsi));
  particleList.push_back(make_shared<Particle>(omega));
}

void CallToActionDisplay::setTextList(){
  xmlTexts.pushTag("textset");
  int numberOfTexts= xmlTexts.getNumTags("text");
  for(int i = 0; i < numberOfTexts; i++){
    xmlTexts.pushTag("text", i);
    string ca = xmlTexts.getValue("ca","");
    string en = xmlTexts.getValue("en","");
    string es = xmlTexts.getValue("es","");
    textList.push_back(CallToActionText(ca,en,es));
    xmlTexts.popTag();
  }
  xmlTexts.popTag();
}

CallToActionDisplay::CallToActionDisplay(){
  setParticleList();
  selectedParticle = 0;
  setTextList();
  selectedText = 0;
}

void CallToActionDisplay::drawImage(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  particleList[selectedParticle]->draw();
  ofPopMatrix();
}

void CallToActionDisplay::drawText(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  textList[selectedText].draw();
  ofPopMatrix();
}


void CallToActionDisplay::update(){
  particleList[selectedParticle]->update();
  textList[selectedText].update();

  if ( ofGetFrameNum() % Parameters::CTATextChange == 0 ){setNewText();}
}

void CallToActionDisplay::setNewParticle(){
  if (selectedParticle==(particleList.size()-1)){selectedParticle = 0;}
  else {selectedParticle +=1;}

}

void CallToActionDisplay::setNewText(){
  if (selectedText==(textList.size()-1)){selectedText = 0;}
  else {selectedText +=1;}

}
