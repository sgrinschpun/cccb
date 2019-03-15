#ifndef _CallToActionDisplay
#define _CallToActionDisplay
#include "ofMain.h"

class CallToActionDisplay {
  private:
    static ofTrueTypeFont myFont;
    void setupFont();


  public:
    void update();
    void draw();
    CallToActionDisplay();

};
#endif
