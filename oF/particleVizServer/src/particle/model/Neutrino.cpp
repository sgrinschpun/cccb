#include "Neutrino.h"

void Neutrino::setXMLSettingsName(){
  const string neutrinos[] = {"nu_e", "nu_mu", "nu_tau"};
  auto it = find(begin(neutrinos), end(neutrinos), data->getName());
  if (it != end(neutrinos)) {xmlSettingsName = "neutrino";}
  else {xmlSettingsName = "neutrino";}
}

void Neutrino::specificParameters(){
  string name = data->getName();
  const string antileptons[] = {"nu_ebar","nu_mubar","nu_taubar"};
  auto it = find(begin(antileptons), end(antileptons), name);
  if (it != end(antileptons)) {
    colMode = 1;
  }

}

Neutrino::Neutrino(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();

}
