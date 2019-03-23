#ifndef _CallToActionController
#define _CallToActionController

#include "ofMain.h"
#include "ListManager.h"
#include "CallToActionDisplay.h"

class CallToActionController {
  private:
		ListManager listManager;

    unique_ptr<CallToActionDisplay> callToActionDisplay;

    unsigned int delay {5000};

    bool callToActionActivate {false};
    unsigned long int delayInit {0};

    bool checkDelay();
    void reset();
    void startCallToAction();
    void stopCallToAction();

  public:
    void drawImage();
    void drawText();
    void update();
    void setup(ListManager &_listManager);

    CallToActionController();
};
#endif
