#ifndef _ProjectFonts //
#define _ProjectFonts //
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class ProjectFonts {

  public:
    static map <string, shared_ptr<ofxCenteredTrueTypeFont> > fontList;
    static void addFont(string _name, shared_ptr<ofxCenteredTrueTypeFont> _font);
    static shared_ptr<ofxCenteredTrueTypeFont>  getFont(string _name);


    void setupFonts();
    ProjectFonts();

};
#endif
