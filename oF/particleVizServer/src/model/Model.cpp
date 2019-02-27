#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Model.h"

Model::Model(shared_ptr<ParticleData>& _data): data(_data){
  buildParameters();
  specificParameters()
  setShape();
}

void Model::buildParameters(){
  settings.pushTag("shape");
    shapesNum.set(settings.getValue("shapesNum", 0));
    radius.set(settings.getValue("radius", 0));
    width.set(settings.getValue("width", 0));
    segments.set(settings.getValue("segments", 0));
    speed.set(settings.getValue("speed", 0.00));
  settings.popTag();
  settings.pushTag("variations");
    settings.pushTag("pos");
      ofVec3f position;
      position.x = settings.getValue("x", 0);
      position.y = settings.getValue("y", 0);
      position.z = settings.getValue("z", 0);
      pos.set(position);
    settings.popTag();
    settings.pushTag("rot");
      ofVec3f rotation;
      rotation.x = settings.getValue("x", 0);
      rotation.y = settings.getValue("y", 0);
      rotation.z = settings.getValue("z", 0);
      rot.set(rotation);
    settings.popTag();
  settings.popTag();
  settings.pushTag("wiggle");
    framesPerCycle.set(settings.getValue("framesPerCycle", 0.00));
    noiseStep.set(settings.getValue("noiseStep", 0.00));
    noiseAmount.set(settings.getValue("noiseAmount", 0.00));
    settings.popTag();
  settings.pushTag("color");
  fadeAmnt.set(settings.getValue("fadeAmnt", 0));
  color_mode.set(settings.getValue("color_mode", 0));
  saturation.set(settings.getValue("saturation", 0));
  brightness.set(settings.getValue("brightness", 0));
  alpha.set(settings.getValue("alpha", 0));
  settings.popTag();
}

void Model::specificParameters(){

}


void Model::setShape(){
    shape = make_shared<WaveRingVariation>();

    shape -> setCycle(framesPerCycle);
    shape -> setShapeNum(shapesNum);
    shape -> setRadius(radius);
    shape -> setWidth(width);
    shape -> setSegments(segments);
    shape -> setSpeed(speed);
    shape -> setPos(pos);
    shape -> setRot(rot);
    shape -> setNoiseStep(noiseStep);
    shape -> setNoiseAmount(noiseAmount);
    shape -> setFadeAmount(fadeAmnt);
    shape -> setColorMode(colMode);
    shape -> setSaturation(saturation);
    shape -> setBrightness(brightness);
    shape -> setAlpha(alpha);
}

void Model::draw(){
    shape->draw();
}

void Model::update(){
    shape->update();
}

void Model::setPosition(ofPoint _position){
  shape->setPosition(_position);
}
