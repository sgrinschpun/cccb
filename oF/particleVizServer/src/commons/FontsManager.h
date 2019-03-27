#ifndef _FontsManager //
#define _FontsManager //
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class FontsManager {

  public:
    static map <string, shared_ptr<ofxCenteredTrueTypeFont> > fontList;
    static void addFont(string _name, shared_ptr<ofxCenteredTrueTypeFont> _font);
    static shared_ptr<ofxCenteredTrueTypeFont>  getFont(string _name);

};
#endif
