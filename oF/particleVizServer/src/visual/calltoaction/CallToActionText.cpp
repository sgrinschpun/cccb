#include "CallToActionText.h"
#include "Parameters.h"

CallToActionText::CallToActionText(string _ca, string _en, string _es):ca(_ca),en(_en), es(_es) {
  ctaFont1 = FontsManager::getFont("MADBold20");
  ctaFont2 = FontsManager::getFont("MADBlack20");
  separation = Parameters::CTATextSeparation;
  padding = Parameters::CTATextPadding;
}

void CallToActionText::draw(){
  ofNoFill();
  ofSetColor(255,255,255);
  ofSetLineWidth(0);
  ctaFont2->drawCenteredBoundingBox(en, 0, -separation, padding);
  ctaFont2->drawStringCentered(en, 0, -separation);
  ctaFont1->drawCenteredBoundingBox(ca, 0, 0, padding);
  ctaFont1->drawStringCentered(ca, 0, 0);
  ctaFont2->drawCenteredBoundingBox(es, 0, separation, padding);
  ctaFont2->drawStringCentered(es, 0, separation);
}

void CallToActionText::update(){

}
