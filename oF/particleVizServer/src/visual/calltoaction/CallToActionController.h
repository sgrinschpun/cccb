#ifndef _CallToActionController
#define _CallToActionController

#include "ofMain.h"
#include "ListManager.h"
#include "CallToActionDisplay.h"

class CallToActionController {
  private:
	  shared_ptr<ListManager> listManager;
    unique_ptr<CallToActionDisplay> callToActionDisplay;


    unsigned int delay;
    bool callToActionActivate;
    unsigned long int delayInit;

    bool checkDelay();
    void startCounting();
    void startCallToAction();
    void stopCallToAction();

  public:
    void drawImage();
    void drawText();
    void update();
    void setup(shared_ptr<ListManager>& _listManager);

    CallToActionController();
};
#endif
