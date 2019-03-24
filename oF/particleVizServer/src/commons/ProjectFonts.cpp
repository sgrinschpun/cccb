#include "ProjectFonts.h"

map <string, shared_ptr<ofxCenteredTrueTypeFont> > ProjectFonts::fontList;

void ProjectFonts::addFont(string _name, shared_ptr<ofxCenteredTrueTypeFont> _font){
  ofLog()<<"added1"<<_name<<_font;
  ProjectFonts::fontList.insert(make_pair(_name, _font));
}

shared_ptr<ofxCenteredTrueTypeFont>   ProjectFonts::getFont(string _name){
  shared_ptr<ofxCenteredTrueTypeFont> font;
  map <string, shared_ptr<ofxCenteredTrueTypeFont>> ::iterator fontIt;
  fontIt = ProjectFonts::fontList.find(_name);
  if (fontIt != ProjectFonts::fontList.end()) {
    ofLog()<<"font found";
    font = fontIt->second;
  }
  else {
    ofLog()<<"font not found";
    ofLog()<<"size"<<ProjectFonts::fontList.size();
    font = nullptr;
  }
  return font;
}

ProjectFonts::ProjectFonts(){
  setupFonts();

}

void ProjectFonts::setupFonts(){

  shared_ptr<ofxCenteredTrueTypeFont> font1= make_shared<ofxCenteredTrueTypeFont>();
  ofTrueTypeFontSettings settings1("Lato-Regular.ttf", 20);
  settings1.antialiased = true;
  settings1.addRange(ofUnicode::Latin1Supplement);
  settings1.addRange(ofUnicode::Latin);
  settings1.addRange(ofUnicode::LatinExtendedAdditional);
  font1 -> load(settings1);
  ProjectFonts::addFont("lato20", font1);

  ofLog() << "ok1";

  shared_ptr<ofxCenteredTrueTypeFont> font2 = make_shared<ofxCenteredTrueTypeFont>();
  ofTrueTypeFontSettings settings2("Lato-Regular.ttf", 10);
  settings2.antialiased = true;
  settings2.addRange(ofUnicode::Latin1Supplement);
  settings2.addRange(ofUnicode::Latin);
  settings2.addRange(ofUnicode::LatinExtendedAdditional);
  font2 -> load(settings2);
  ProjectFonts::addFont("lato10", font2);

  ofLog() << "ok2";
}
