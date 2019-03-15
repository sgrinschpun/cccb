#include "CallToActionController.h"

CallToActionController::CallToActionController(map <int, shared_ptr<Particle> > *_particleMap): particleMap(_particleMap) {
  callToActionDisplay = make_unique<CallToActionDisplay>();
}


bool CallToActionController::isEmpty(){
  bool status = false;
  if (particleMap->size()==0) {
    status = true;
    if (delayInit == 0) {
      delayInit = ofGetElapsedTimeMillis();
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
  if (isEmpty()){
    if (checkDelay()){startCallToAction();}
  }
  else {
    stopCallToAction();
  }
  callToActionDisplay->update();
}

void CallToActionController::draw(){
  if (callToActionActivate) {
    callToActionDisplay->draw();
  }
}
