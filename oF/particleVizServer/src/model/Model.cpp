#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Model.h"

map <string, ofxXmlSettings >  Model::xmlSettings = setXMLsettings();

map <string, ofxXmlSettings >  Model::setXMLsettings(){
  map <string, ofxXmlSettings > m;
  m["quark"] = ofxXmlSettings();
  m["quark"].loadFile("quark.xml");
  m["neutrino"] = ofxXmlSettings();
  m["neutrino"].loadFile("neutrino.xml");
  m["antineutrino"] = ofxXmlSettings();
  m["antineutrino"].loadFile("antineutrino.xml");
  m["meson"] = ofxXmlSettings();
  m["meson"].loadFile("meson.xml");
  m["baryon"] = ofxXmlSettings();
  m["baryon"].loadFile("baryon.xml");
  m["gamma"] = ofxXmlSettings();
  m["gamma"].loadFile("gamma.xml");
  m["W"] = ofxXmlSettings();
  m["W"].loadFile("W.xml");
  m["Z0"] = ofxXmlSettings();
  m["Z0"].loadFile("Z0.xml");
  m["h0(H_1)"] = ofxXmlSettings();
  m["h0(H_1)"].loadFile("higgs.xml");
  m["electron"] = ofxXmlSettings();
  m["electron"].loadFile("electron.xml");
  m["muon"] = ofxXmlSettings();
  m["muon"].loadFile("muon.xml");
  m["tau"] = ofxXmlSettings();
  m["tau"].loadFile("tau.xml");
  m["positron"] = ofxXmlSettings();
  m["positron"].loadFile("positron.xml");
  m["antimuon"] = ofxXmlSettings();
  m["antimuon"].loadFile("antimuon.xml");
  m["antitau"] = ofxXmlSettings();
  m["antitau"].loadFile("antitau.xml");
  return m;
}

void Model::setXMLSettingsName(){

}


Model::Model(shared_ptr<ParticleData>& _data): data(_data){
  buildParameters(xmlSettings[xmlSettingsName]);
  specificParameters();
  setShape();
}

void Model::buildParameters(ofxXmlSettings& settings){
  //cout << "name" << xmlSettingsName << endl;
  //ofxXmlSettings settings = xmlSettings[xmlSettingsName];

  settings.pushTag("shape");
    shapesNum = settings.getValue("shapesNum", 0);
    radius = settings.getValue("radius", 0);
    width = settings.getValue("width", 0);
    segments = settings.getValue("segments", 0);
    speed = settings.getValue("speed", 0.00);
  settings.popTag();
  settings.pushTag("variations");
    settings.pushTag("pos");
      pos.x = settings.getValue("x", 0);
      pos.y = settings.getValue("y", 0);
      pos.z = settings.getValue("z", 0);
    settings.popTag();
    settings.pushTag("rot");
      rot.x = settings.getValue("x", 0);
      rot.y = settings.getValue("y", 0);
      rot.z = settings.getValue("z", 0);
    settings.popTag();
  settings.popTag();
  settings.pushTag("wiggle");
    framesPerCycle = settings.getValue("framesPerCycle", 0.00);
    noiseStep = settings.getValue("noiseStep", 0.00);
    noiseAmount = settings.getValue("noiseAmount", 0.00);
    settings.popTag();
  settings.pushTag("color");
  fadeAmnt = settings.getValue("fadeAmnt", 0);
  colMode = settings.getValue("colMode", 0);
  saturation = settings.getValue("saturation", 0);
  brightness = settings.getValue("brightness", 0);
  alpha = settings.getValue("alpha", 0);
  settings.popTag();
}

void Model::specificParameters(){

}


void Model::setShape(){
    shape = make_shared<WaveRingVariation>();

    shape -> setCycle(framesPerCycle);
    shape -> setShapeNum(shapesNum);
    shape -> setRadius(radius);
    shape -> setWidth(width);
    shape -> setSegments(segments);
    shape -> setSpeed(speed);
    shape -> setPos(pos);
    shape -> setRot(rot);
    shape -> setNoiseStep(noiseStep);
    shape -> setNoiseAmount(noiseAmount);
    shape -> setFadeAmnt(fadeAmnt);
    shape -> setColorMode(colMode);
    shape -> setSaturation(saturation);
    shape -> setBrightness(brightness);
    shape -> setAlpha(alpha);
}

void Model::draw(){
    shape->draw();
}

void Model::update(){
    shape->update();
}

void Model::setPosition(ofPoint _position){
  shape->setPosition(_position);
}
