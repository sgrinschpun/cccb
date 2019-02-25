//
//  PhenomenaParams.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include <stdio.h>
#include <string>
using namespace std;

struct PhenomenaParams{
    int id;
    int parent;
    string name;
    float mass;
    float charge;
    string type;
    float energy;
    float vx;
    float vy;
    float vz;
    float beta;

    // string composition[2];
    // string  decay_time[2];


    bool equals(PhenomenaParams p) {
        return id == p.id;
    }
};
