#include "CallToActionText.h"
#include "Parameters.h"

CallToActionText::CallToActionText(string _ca, string _en, string _es):ca(_ca),en(_en), es(_es) {
  ctaFont = FontsManager::getFont("MADBold20");
  separation = Parameters::CTATextSeparation;
  padding = Parameters::CTATextPadding;
}

void CallToActionText::draw(){
  ofNoFill();
  ofSetColor(255,255,255);
  ofSetLineWidth(0);
  ctaFont->drawCenteredBoundingBox(en, 0, -separation, padding);
  ctaFont->drawStringCentered(en, 0, -separation);
  ctaFont->drawCenteredBoundingBox(ca, 0, 0, padding);
  ctaFont->drawStringCentered(ca, 0, 0);
  ctaFont->drawCenteredBoundingBox(es, 0, separation, padding);
  ctaFont->drawStringCentered(es, 0, separation);
}

void CallToActionText::update(){

}
