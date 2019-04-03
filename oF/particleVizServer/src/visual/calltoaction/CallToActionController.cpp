#include "CallToActionController.h"
#include "Parameters.h"

CallToActionController::CallToActionController() {

}

void CallToActionController::setup(shared_ptr<ListManager>& _listManager){
  listManager = _listManager;
  callToActionDisplay = make_unique<CallToActionDisplay>();
  delay = Parameters::CTADelay;
  callToActionActivate=false;
  delayInit=0;
}


bool CallToActionController::checkDelay(){
  bool status = false;
  unsigned long int actualTime = ofGetElapsedTimeMillis();
  if (actualTime - delayInit >= delay){
    status = true;
  }
  return status;
}

void CallToActionController::startCounting(){
  delayInit = ofGetElapsedTimeMillis();
}

void CallToActionController::startCallToAction(){
  callToActionActivate = true;
}

void CallToActionController::stopCallToAction(){
  callToActionActivate = false;
  delayInit = 0;
  callToActionDisplay->setNewParticle();
}

void CallToActionController::update(){
  if (listManager->isScreenEmpty() && delayInit==0) {startCounting();}
  else if (listManager->isScreenEmpty() && delayInit!=0) {
    if (checkDelay()){startCallToAction();}
  }
  else if (callToActionActivate == true){stopCallToAction();}
  callToActionDisplay->update();
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
