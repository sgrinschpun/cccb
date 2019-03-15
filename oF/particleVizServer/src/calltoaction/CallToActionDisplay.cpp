#include "CallToActionDisplay.h"

ofTrueTypeFont CallToActionDisplay::myFont;

void CallToActionDisplay::setupFont(){
  if (!myFont.isLoaded()){
    myFont.load("Lato-Regular.ttf",30);
  }
}

CallToActionDisplay::CallToActionDisplay(){
  setupFont();
}

void CallToActionDisplay::draw(){
  myFont.drawString("Enter the Dragon", ofGetWidth()/2, ofGetHeight()/2);
}

void CallToActionDisplay::update(){

}
