#include "Fonts.h"

ofxCenteredTrueTypeFont Fonts::font;

void Fonts::setupFont(){
  ofTrueTypeFontSettings settings("Lato-Regular.ttf", 20);
	settings.antialiased = true;
	settings.addRange(ofUnicode::Latin1Supplement);
	settings.addRange(ofUnicode::Latin);
	settings.addRange(ofUnicode::LatinExtendedAdditional);
  if (!font.isLoaded()){
    font.load(settings);
  }
}
