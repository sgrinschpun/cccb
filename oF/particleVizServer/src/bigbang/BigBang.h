#ifndef _BigBang
#define _BigBang
#include "ofMain.h"
#include "FontsManager.h"
#include "ofxCenteredTrueTypeFont.h"

class BigBang {

private:
  shared_ptr<ofxCenteredTrueTypeFont> bigBangFont{FontsManager::getFont("MADBlack200")};

public:
  void setup();
  //void update();
  void draw();

  BigBang();


};
#endif
