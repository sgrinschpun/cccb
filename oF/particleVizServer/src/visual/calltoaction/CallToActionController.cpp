#include "CallToActionController.h"

CallToActionController::CallToActionController(shared_ptr<map <int, shared_ptr<Particle>>> _particleMap): particleMap(_particleMap) {
  ofLog() << "calltoaction init 1";
  callToActionDisplay = make_unique<CallToActionDisplay>();
}


bool CallToActionController::isEmpty(){
  bool status = false;
  if (particleMap->size()==0) {
    status = true;
    if (delayInit == 0) {
      delayInit = ofGetElapsedTimeMillis();
      callToActionDisplay->setNew();
    }
  }
  return status;
}

bool CallToActionController::checkDelay(){
  bool status = false;
  unsigned long int actualTime = ofGetElapsedTimeMillis();
  if (actualTime - delayInit >= delay){
    status = true;
  }
  return status;
}

void CallToActionController::startCallToAction(){
  callToActionActivate = true;
}

void CallToActionController::stopCallToAction(){
  callToActionActivate = false;
  delayInit = 0;
}

void CallToActionController::update(){
  ofLog() << "calltoaction update 1";
  if (isEmpty()){
    if (checkDelay()){startCallToAction();}
  }
  else {
    stopCallToAction();
  }
  callToActionDisplay->update();
  ofLog() << "calltoaction update 2";
}

void CallToActionController::drawImage(){
  if (callToActionActivate) {
    callToActionDisplay->drawImage();
  }
}

void CallToActionController::drawText(){
  if (callToActionActivate) {
    callToActionDisplay->drawText();
  }
}
