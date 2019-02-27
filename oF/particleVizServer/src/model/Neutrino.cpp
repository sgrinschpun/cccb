#include "Neutrino.h"

ofxXmlSettings Neutrino::settings = setXMLsettings();

ofxXmlSettings Neutrino::setXMLsettings(){
  const string neutrinos[] = {"nu_e", "nu_mu", "nu_tau"};
  ofxXmlSettings set;
  auto it = find(begin(neutrinos), end(neutrinos), data->getName());
  if (it != end(neutrinos)) {set.loadFile("settings.xml");}
  else {set.loadFile("settings.xml");}
  return set
}

Neutrino::Neutrino(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
