//
//  PhenomenaCMD.cpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#include "PhenomenaCMD.hpp"
#include "PhenomenaParams.hpp"

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
