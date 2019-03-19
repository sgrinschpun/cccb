#include "CallToActionText.h"

ofxCenteredTrueTypeFont CallToActionText::myFont;

void CallToActionText::setupFont(){
  ofTrueTypeFontSettings settings("Lato-Regular.ttf", 20);
	settings.antialiased = true;
	settings.addRange(ofUnicode::Latin1Supplement);
	settings.addRange(ofUnicode::Latin);
	settings.addRange(ofUnicode::LatinExtendedAdditional);
  if (!myFont.isLoaded()){
    myFont.load(settings);
  }
}

CallToActionText::CallToActionText(string _ca, string _en, string _es):ca(_ca),en(_en), es(_es) {
  setupFont();
}

void CallToActionText::draw(){
  ofNoFill();
  ofSetColor(255,255,255);
  ofSetLineWidth(0);
  myFont.drawCenteredBoundingBox(en, 0, -100, padding);
  myFont.drawStringCentered(en, 0, -100);
  myFont.drawCenteredBoundingBox(ca, 0, 0, padding);
  myFont.drawStringCentered(ca, 0, 0);
  myFont.drawCenteredBoundingBox(es, 0, 100, padding);
  myFont.drawStringCentered(es, 0, 100);
}

void CallToActionText::update(){

}
