#ifndef _ProjectFonts //
#define _ProjectFonts //
#include "ofMain.h"
#include "FontsManager.h"
#include "ofxCenteredTrueTypeFont.h"

class ProjectFonts {

  public:
    string path{"fonts/"};
    void setupFont(string _fontname, int _fontsize, string _key);
    void setupFonts();
    ProjectFonts();

};
#endif
