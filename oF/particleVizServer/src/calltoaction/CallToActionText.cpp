#include "CallToActionText.h"

CallToActionText::CallToActionText(string _ca, string _en, string _es):ca(_ca),en(_en), es(_es) {
  ctaFont = ProjectFonts::getFont("lato20");
}

void CallToActionText::draw(){
  ofNoFill();
  ofSetColor(255,255,255);
  ofSetLineWidth(0);
  ctaFont->drawCenteredBoundingBox(en, 0, -100, padding);
  ctaFont->drawStringCentered(en, 0, -100);
  ctaFont->drawCenteredBoundingBox(ca, 0, 0, padding);
  ctaFont->drawStringCentered(ca, 0, 0);
  ctaFont->drawCenteredBoundingBox(es, 0, 100, padding);
  ctaFont->drawStringCentered(es, 0, 100);
}

void CallToActionText::update(){

}
