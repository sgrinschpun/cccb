#ifndef _VisualManager
#define _VisualManager

#include "ofMain.h"
#include "CallToActionController.h"
#include "ListManager.h"

class VisualManager{

private:
  shared_ptr<ListManager> listManager;

  ofFbo rgbaFbo;
  float fboWidth;
  float fboHeight;
  void setupFbo();
  void drawFbo();
  float fadeAmnt;

  CallToActionController callToAction;

public:
  void setup(shared_ptr<ListManager>& _listManager);
  void update();
  void draw();

  VisualManager();
};
#endif
