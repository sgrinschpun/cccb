#include "ParticleData.h"

ParticleData::ParticleData(int _id, int _parent, string _name, float _mass, float _charge, string _type, float _energy): id(_id), parent(_parent), name(_name), mass(_mass), charge(_charge), type(_type), energy(_energy){
}

int ParticleData::getId(void){
  return id;
}

int ParticleData::getParent(void){
  return parent;
}

string ParticleData::getName(void){
  return name;
}

string ParticleData::getType(void){
  return type;
}

float ParticleData::getMass(void){
  return mass;
}

float ParticleData::getCharge(void){
  return charge;
}

float ParticleData::getEnergy(void){
  return energy;
}
