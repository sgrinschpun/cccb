#include "Lepton.h"

ofxXmlSettings Boson::settings = setXMLsettings();

ofxXmlSettings Boson::setXMLsettings(){
  ofxXmlSettings set;
  // switch(data->getName()){
  //   case "e-":
  //     set.loadFile("electron.xml");
  //     break;
  //   case "mu-":
  //     set.loadFile("muon.xml");
  //     break;
  //   case "tau-":
  //     set.loadFile("tau.xml");
  //     break;
  //   case "e+":
  //     set.loadFile("positron.xml");
  //     break;
  //   case "mu+":
  //     set.loadFile("antimuon.xml");
  //     break;
  //   case "tau+":
  //     set.loadFile("antitau.xml");
  //     break;
  // }
  set.loadFile("settings.xml");
  return set
}


Lepton::Lepton(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
