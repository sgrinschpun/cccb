#ifndef _CallToActionController
#define _CallToActionController
#include "ofMain.h"
#include "Particle.h"
#include "CallToActionDisplay.h"

class CallToActionController {

  private:
    map<int, shared_ptr<Particle>> *particleMap;
    unique_ptr<CallToActionDisplay> callToActionDisplay;

    unsigned int delay {5000};

    bool callToActionActivate {false};
    unsigned long int delayInit {0};
    bool isEmpty();
    bool checkDelay();
    void startCallToAction();
    void stopCallToAction();

  public:
    void drawImage();
    void drawText();
    void update();

    CallToActionController(map <int, shared_ptr<Particle> > *_particleMap);
};
#endif
