#ifndef _ParticleData //
#define _ParticleData //
#include "ofMain.h"

class ParticleData {
  private:
    int id;
    int parent;
    string name;
    float mass;
    float charge;
    string type;
    float energy;

  public:
    int getId();
    int getParent();
    string getName();
    float getMass();
    float getCharge();
    string getType();
    float getEnergy();

    ParticleData(int _id, int _parent, string _name, float _mass, float _charge, string _type, float _energy);

    ~ParticleData() {}

};
#endif
