#include "PhenomenaCMD.h"
#include "PhenomenaParams.h"

PhenomenaCMD::PhenomenaCMD(string cmd, PhenomenaParams params){
    _cmd = cmd;
    _params = params;
}

string PhenomenaCMD::getCMD(){
    return _cmd;
}

PhenomenaParams PhenomenaCMD::getParams(){
    return _params;
}
