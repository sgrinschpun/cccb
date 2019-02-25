//
//  ListManager.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include <stdio.h>
#include "VisualManager.hpp"
#include "PhenomenaCMD.hpp"

class AudioVisualManager{
    VisualManager vManager;
public:
    AudioVisualManager();
    void update(PhenomenaCMD phenoCMD);
    void visualize();
};
