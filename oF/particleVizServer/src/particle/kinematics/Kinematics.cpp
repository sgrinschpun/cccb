#include "Kinematics.h"
#include "Parameters.h"

float Kinematics::BMag{Parameters::BMag};
float Kinematics::velocityAmp{Parameters::velocityAmp};

Kinematics::Kinematics(shared_ptr<ParticleData>& _particleData, ofVec2f _position, ofVec2f _velocity): data(_particleData), position(_position), velocity(_velocity){
  acceleration.set(0,0);
  velocity *= Parameters::velocityAmp;
}

void Kinematics::setBforce(){
  float q = data->getCharge();
  float mass = data->getMass();
  ofVec2f perpendicular= velocity.getPerpendicular();
  Bforce = Parameters::BMag*perpendicular*q/mass;
}

void Kinematics::setVelocity(){
  float elapsedTime = 50*ofGetElapsedTimeMillis() - initTime;
  float speed = initSpeed/(1+pow(elapsedTime,2))+ finalSpeed;
  velocity.normalize();
  velocity *= speed;
}


void Kinematics::applyForce(ofVec2f _vector){
  acceleration += _vector;
}


void Kinematics::update(){
  setBforce();
  applyForce(Bforce);
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;

}

ofVec2f Kinematics::getPosition(){
  return position;
}

ofVec2f Kinematics::getVelocity(){
  return velocity;
}

void Kinematics::checkEdges(){
  if (position.x > ofGetWidth()) {
      position.x = 0;
  }
  if (position.x < 0) {
      position.x = ofGetWidth();
  }
  if (position.y > ofGetHeight()) {
      position.y = 0;
  }
  if (position.y < 0) {
      position.y = ofGetHeight();
  }
}


float Kinematics::getDistance(){
  ofVec3f center(3, 4, 2);
  return position.distance(center);
}
