#ifndef _PhenomenaCMD
#define _PhenomenaCMD
#include "PhenomenaParams.h"
using namespace std;

class PhenomenaCMD{
    string _cmd;
    PhenomenaParams _params;
public:
    PhenomenaCMD(string cmd, PhenomenaParams params);
    string getCMD();
    PhenomenaParams getParams();

};
#endif
