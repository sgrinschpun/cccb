#ifndef _Kinematics
#define _Kinematics
#include "ofMain.h"
#include "ParticleData.h"

class Kinematics {
  private:
    shared_ptr<ParticleData> data;
    ofPoint position;
    ofVec3f velocity;
    ofVec3f acceleration;

    void setInitialSpeed();
    ofVec3f applyForce(ofVec3f _vector);

    ofVec3f Bfield;
    ofVec3f Bforce;
    void setBforce();
    ofVec3f DragForce;
    void setDragFroce();

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
