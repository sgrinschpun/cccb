#include "Parameters.h"

shared_ptr<ofxXmlSettings> Parameters::xmlParameters=make_shared<ofxXmlSettings>("parameters.xml");
/*
shared_ptr<ofxXmlSettings> Parameters::setXMLParameters(){
  shared_ptr<ofxXmlSettings> p;
  p = make_shared<ofxXmlSettings>("/home/cristobal/development/particle_muzic_CCCB/oF/particleVizServer/bin/data/parameters.xml");
  return p;
}
*/
float Parameters::BMag = setBMag();
float Parameters::setBMag(){
  return xmlParameters->getValue("magneticField", 0.0);
}

float Parameters::velocityAmp = setVelocityAmp();
float Parameters::setVelocityAmp(){
  return xmlParameters->getValue("velocity", 0.0);
}

float Parameters::fadeAmnt = setFadeAmnt();
float Parameters::setFadeAmnt(){
  return xmlParameters->getValue("fadeAmnt", 0.0);
}

float Parameters::baseRadius = setBaseRadius();
float Parameters::setBaseRadius(){
  return xmlParameters->getValue("baseRadius", 0.0);
}
