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


void Info::drawInfo(ofVec2f& _velocity){
  ofVec2f textPosition = _velocity.getNormalized().getScaled(radius);

  string name = data->getName();
  float mass = data->getMass();
  myFont.drawString(name, textPosition.x+30, textPosition.y+30);
  //myFont.drawString(to_string(mass), textPosition.x, textPosition.y-30);
}
