#include "Neutrino.h"

void Neutrino::setXMLSettingsName(){
  const string neutrinos[] = {"nu_e", "nu_mu", "nu_tau"};
  auto it = find(begin(neutrinos), end(neutrinos), data->getName());
  if (it != end(neutrinos)) {xmlSettingsName = "neutrino";}
  else {xmlSettingsName = "neutrino";}
}

void Neutrino::specificParameters(){

}

Neutrino::Neutrino(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  setShape();
  specificParameters();

}
