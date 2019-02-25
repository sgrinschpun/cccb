//
//  PhenomenaCMD.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include <stdio.h>
#include "PhenomenaParams.hpp"

class PhenomenaCMD{
    string _cmd;
    PhenomenaParams _params;
public:
    PhenomenaCMD(string cmd, PhenomenaParams params);
    string getCMD();
    PhenomenaParams getParams();
    
};
