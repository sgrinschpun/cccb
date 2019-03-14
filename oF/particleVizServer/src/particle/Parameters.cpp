#include "Parameters.h"

shared_ptr<ofxXmlSettings> Parameters::xmlParameters=make_shared<ofxXmlSettings>("parameters.xml");

shared_ptr<ofxXmlSettings> Parameters::setXMLParameters(){
  shared_ptr<ofxXmlSettings> p;
  p = make_shared<ofxXmlSettings>("parameters.xml");
  return p;
}

float Parameters::BMag = setBMag();
float Parameters::setBMag(){
  //unique_ptr<ofxXmlSettings>& parameters =xmlParameters;
  //xmlParameters->pushTag("kinematics");
  return xmlParameters->getValue("magneticField", 0.0);
  //xmlParameters->popTag();
}

float Parameters::velocityAmp = setVelocityAmp();
float Parameters::setVelocityAmp(){
  //unique_ptr<ofxXmlSettings>& parameters =xmlParameters;
  //xmlParameters->pushTag("kinematics");
  return xmlParameters->getValue("velocity", 0.0);
  //xmlParameters->popTag();
}

float Parameters::fadeAmnt = setFadeAmnt();
float Parameters::setFadeAmnt(){
  //unique_ptr<ofxXmlSettings>& parameters =xmlParameters;
  //xmlParameters->pushTag("appearence");
  return xmlParameters->getValue("fadeAmnt", 0.0);
  //xmlParameters->popTag();
}

float Parameters::baseRadius = setBaseRadius();
float Parameters::setBaseRadius(){
  //unique_ptr<ofxXmlSettings>& parameters =xmlParameters;
  //xmlParameters->pushTag("appearence");
  return xmlParameters->getValue("baseRadius", 0.0);
  //xmlParameters->popTag();
}

 Parameters::Parameters(){

 }
