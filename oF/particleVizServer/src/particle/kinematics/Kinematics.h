#ifndef _Kinematics
#define _Kinematics
#include "ofMain.h"
#include "ParticleData.h"

class Kinematics {
  private:
    shared_ptr<ParticleData> data;
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;

    void setInitialSpeed();
    ofVec3f applyForce(ofVec3f _vector);

    //ofVec3f Bfield;
    ofVec2f Bforce;
    void setBforce();

    float initTime;
    float initSpeed;
    void setVelocity();
    float finalSpeed;

    void checkEdges();

  public:
    void update();
    ofPoint getPosition();
    float getDistance();



    Kinematics(shared_ptr<ParticleData>& _particleData, ofPoint _position, ofVec3f _velocity);

};
#endif
