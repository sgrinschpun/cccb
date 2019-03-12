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
    ofVec2f applyForce(ofVec3f _vector);

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
    ofVec2f getPosition();
    ofVec2f getVelocity();
    float getDistance();



    Kinematics(shared_ptr<ParticleData>& _particleData, ofVec2f _position, ofVec2f _velocity);

};
#endif
