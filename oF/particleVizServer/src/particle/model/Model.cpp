#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Model.h"

map <string, string> Model::xmlSettingsNames = setXMLSettingsNames();
map <string, string> Model::setXMLSettingsNames(){
  map <string, string> m;
  m["quark"] = "quark.xml";
  m["neutrino"] = "neutrino.xml";
  m["meson"] = "meson.xml";
  m["baryon"] = "baryon.xml";
  m["gamma"] = "gamma.xml";
  m["W"] = "W.xml";
  m["Z0"] = "Z0.xml";
  m["higgs"] = "higgs.xml";
  m["electron"] = "electron.xml";
  m["muon"] = "muon.xml";
  m["tau"] = "tau.xml";
  return m;
}

map <string, unique_ptr<ofxXmlSettings> > Model::xmlSettings = setXMLsettings();
map <string, unique_ptr<ofxXmlSettings> > Model::setXMLsettings(){
  map <string, unique_ptr<ofxXmlSettings> > m;
  for (map <string, string> ::iterator xmlSettingsNamesIt = xmlSettingsNames.begin(); xmlSettingsNamesIt != xmlSettingsNames.end(); xmlSettingsNamesIt++){
    m.insert(make_pair(xmlSettingsNamesIt->first, make_unique<ofxXmlSettings>(xmlSettingsNamesIt->second)));
  }
  return m;
}

Model::Model(shared_ptr<ParticleData>& _data): data(_data){

}

void Model::buildParameters(){
  map <string, unique_ptr<ofxXmlSettings> > ::iterator xmlSettingsIt = xmlSettings.find(xmlSettingsName);
  if (xmlSettingsIt != xmlSettings.end()) {
    unique_ptr<ofxXmlSettings>& settings = xmlSettingsIt->second;
    settings->pushTag("shape");
      shapesNum = settings->getValue("shapesNum", 0);
      radius = settings->getValue("radius", 0);
      width = settings->getValue("width", 0);
      segments = settings->getValue("segments", 0);
      speedAmp = settings->getValue("speedAmp", 0.00);
    settings->popTag();
    settings->pushTag("variations");
      settings->pushTag("posAmp");
        posAmp.x = settings->getValue("x", 0);
        posAmp.y = settings->getValue("y", 0);
        posAmp.z = settings->getValue("z", 0);
      settings->popTag();
      settings->pushTag("rotAmp");
        rotAmp.x = settings->getValue("x", 0);
        rotAmp.y = settings->getValue("y", 0);
        rotAmp.z = settings->getValue("z", 0);
      settings->popTag();
    settings->popTag();
    settings->pushTag("wiggle");
      framesPerCycle = settings->getValue("framesPerCycle", 0.00);
      noiseStep = settings->getValue("noiseStep", 0.00);
      noiseAmount = settings->getValue("noiseAmount", 0.00);
      settings->popTag();
    settings->pushTag("color");
    fadeAmnt = settings->getValue("fadeAmnt", 0);
    colMode = settings->getValue("colMode", 0);
    saturation = settings->getValue("saturation", 0);
    brightness = settings->getValue("brightness", 0);
    alpha = settings->getValue("alpha", 0);
    settings->popTag();
    DEBUG_MSG("Parameters");
    DEBUG_MSG("shapesNum: " + to_string(shapesNum));
    DEBUG_MSG("SpeedAmp: " + to_string(speedAmp));
    DEBUG_MSG("framesPerCycle: " + to_string(framesPerCycle));
    DEBUG_MSG("fadeAmnt: " + to_string(fadeAmnt));

  }
  else {
    DEBUG_MSG("no settings for " + xmlSettingsName);
  }

}


void Model::setShape(){
    shape = make_unique<WaveRingVariation>();

    shape -> setCycle(framesPerCycle);
    shape -> setShapeNum(shapesNum);
    shape -> setRadius(radius);
    shape -> setWidth(width);
    shape -> setSegments(segments);
    shape -> setSpeedAmp(speedAmp);
    shape -> setPosAmp(posAmp);
    shape -> setRotAmp(rotAmp);
    shape -> setNoiseStep(noiseStep);
    shape -> setNoiseAmount(noiseAmount);
    shape -> setFadeAmnt(fadeAmnt);
    shape -> setColorMode(colMode);
    shape -> setSaturation(saturation);
    shape -> setBrightness(brightness);
    shape -> setAlpha(alpha);
}

void Model::setInfo(){
  info = make_unique<Info>(data, radius);
}
void Model::drawInfo(ofVec2f& _velocity){
  info -> drawInfo(_velocity);
}


void Model::draw(){
    shape->draw();
}

void Model::update(){
    shape->update();
}
