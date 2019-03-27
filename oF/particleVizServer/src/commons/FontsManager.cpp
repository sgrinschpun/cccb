#include "FontsManager.h"

map <string, shared_ptr<ofxCenteredTrueTypeFont> > FontsManager::fontList;

void FontsManager::addFont(string _name, shared_ptr<ofxCenteredTrueTypeFont> _font){
  FontsManager::fontList.insert(make_pair(_name, _font));
}

shared_ptr<ofxCenteredTrueTypeFont>   FontsManager::getFont(string _name){
  shared_ptr<ofxCenteredTrueTypeFont> font;
  map <string, shared_ptr<ofxCenteredTrueTypeFont>> ::iterator fontIt;
  fontIt = FontsManager::fontList.find(_name);
  if (fontIt != FontsManager::fontList.end()) {
    font = fontIt->second;
  }
  else {
    font = nullptr;
  }
  return font;
}
