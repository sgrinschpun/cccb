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

int Parameters::OSCInPort = setOSCInPort();
int Parameters::setOSCInPort(){
  return xmlParameters->getValue("OSCInPort", 12345);
}

int Parameters::OSCOutPort = setOSCOutPort();
int Parameters::setOSCOutPort(){
  return xmlParameters->getValue("OSCOutPort", 12347);
}

int Parameters::OSCKillPort = setOSCKillPort();
int Parameters::setOSCKillPort(){
  return xmlParameters->getValue("OSCKillPort", 9999);
}

int Parameters::maxNumPart = setMaxNumPart();
int Parameters::setMaxNumPart(){
  return xmlParameters->getValue("maxNumPart", 200);
}

int Parameters::CTADelay = setCTADelay();
int Parameters::setCTADelay(){
  return xmlParameters->getValue("CTADelay", 5000);
}

int Parameters::CTATextChange = setCTATextChange();
int Parameters::setCTATextChange(){
  return xmlParameters->getValue("CTATextChange", 480);
}

int Parameters::CTATextSeparation = setCTATextSeparation();
int Parameters::setCTATextSeparation(){
  return xmlParameters->getValue("CTATextSeparation", 150);
}

int Parameters::CTATextPadding = setCTATextPadding();
int Parameters::setCTATextPadding(){
  return xmlParameters->getValue("CTATextPadding", 20);
}
