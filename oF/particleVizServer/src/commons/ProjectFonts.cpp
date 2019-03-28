#include "ProjectFonts.h"


ProjectFonts::ProjectFonts(){
  setupFonts();
}

void ProjectFonts::setupFont(string _fontname, int _fontsize, string _key){
  shared_ptr<ofxCenteredTrueTypeFont> font= make_shared<ofxCenteredTrueTypeFont>();
  ofTrueTypeFontSettings settings(path+_fontname, _fontsize);
  settings.antialiased = true;
  settings.addRange(ofUnicode::Latin1Supplement);
  settings.addRange(ofUnicode::Latin);
  settings.addRange(ofUnicode::LatinExtendedAdditional);
  settings.addRange(ofUnicode::Greek);
  settings.addRange(ofUnicode::GreekExtended);
  settings.addRange(ofUnicode::GeneralPunctuation);
  settings.addRange(ofUnicode::SuperAndSubScripts);
  settings.addRange(ofUnicode::CurrencySymbols);
  settings.addRange(ofUnicode::LetterLikeSymbols);
  settings.addRange(ofUnicode::NumberForms);
  settings.addRange(ofUnicode::Arrows);
  settings.addRange(ofUnicode::MathOperators);
  settings.addRange(ofUnicode::MiscTechnical);
  font -> load(settings);
  FontsManager::addFont(_key, font);
}


void ProjectFonts::setupFonts(){
  setupFont("Lato-Regular.ttf", 20, "lato20");
  setupFont("Lato-Regular.ttf", 10, "lato10");
  setupFont("MAD_Sans_Fill_Bold.otf", 20, "MADBold20");
  setupFont("MAD_Sans_Fill_Bold.otf", 10, "MADBold10");
  setupFont("MAD_Sans_Fill_Bold_Italic.otf", 20, "MADBoldItalic20");
  setupFont("MAD_Sans_Fill_Black.otf", 200, "MADBlack200");
  setupFont("MAD_Sans_Fill_Black_Italic.otf", 20, "MADBlackItalic20");
  setupFont("Symbol.ttf", 10, "symbol10");
  setupFont("Menlo.ttc", 10, "menlo10");
}
