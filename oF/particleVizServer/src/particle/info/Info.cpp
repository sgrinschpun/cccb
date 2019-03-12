#include "Info.h"

Info::Info(shared_ptr<ParticleData>& _data, float _radius): data(_data), radius(_radius){
  setupFont();
}

ofTrueTypeFont Info::myFont;

void Info::setupFont(){
  if (!myFont.isLoaded()){
    myFont.load("Lato-Regular.ttf",10);
  }
}


void Info::drawInfo(){
  string name = data->getName();
  float mass = data->getMass();
  myFont.drawString(name, radius, -radius);
  myFont.drawString(to_string(mass), radius, -radius-30);
}
