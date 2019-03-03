//
//  VisualManager.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include <iostream>
#include <map>
#include "PhenomenaCMD.hpp"
#include "Particle.h"
#include "ParticleData.h"
#include <memory>
using namespace std;

class VisualManager{
  map <int, shared_ptr<Particle> > particleMap;
  map <int, shared_ptr<Particle> > ::iterator particleIt;

public:
  VisualManager();
  void updateMap(PhenomenaCMD phenoCMD);
  void update();
  void draw();

  ofFbo rgbaFbo;
  float fboWidth;
  float fboHeight;
  void setupFbo();
  void drawFbo();

  vector<ofPixels> pixs;
  void setupPixs();
  ofImage img;



  //fbo.readPixels(pix[loopCount].getPixelsRef());
  //image.setFromPixels(pix[loopCount].getPixelsRef());

};
