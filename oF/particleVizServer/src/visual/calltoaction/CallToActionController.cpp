#include "CallToActionController.h"

CallToActionController::CallToActionController() {

}

void CallToActionController::setup(ListManager &_listManager) {
  listManager = _listManager;
  callToActionDisplay = make_unique<CallToActionDisplay>();
}


void CallToActionController::reset(){
  if (listManager.listIsEmpty()) {
    if (delayInit == 0) {
      delayInit = ofGetElapsedTimeMillis();
      callToActionDisplay->setNew();
    }
  }
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
  if (listManager.listIsEmpty()){
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
