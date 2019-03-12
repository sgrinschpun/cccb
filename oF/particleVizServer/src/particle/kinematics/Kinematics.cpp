#include "Kinematics.h"

Kinematics::Kinematics(shared_ptr<ParticleData>& _particleData, ofVec2f _position, ofVec2f _velocity): data(_particleData), position(_position), velocity(_velocity){

  //Bfield.set(0,0,0.0000015);
  acceleration.set(0,0);
  //initSpeed = 30;
  //finalSpeed = velocity.length();
  //initTime = 50*ofGetElapsedTimeMillis();
  velocity *= 1.5;
}

void Kinematics::setBforce(){
  float q = data->getCharge();
  float mass = data->getMass();
  ofVec2f perpendicular= velocity.getPerpendicular();
  Bforce = 0.0000015*perpendicular*q/mass;
  //velocity.getCrossed(Bfield)*q/mass;
}

void Kinematics::setVelocity(){
  float elapsedTime = 50*ofGetElapsedTimeMillis() - initTime;
  //float speed = initSpeed*exp(-pow(elapsedTime,2)/10) + finalSpeed;
  float speed = initSpeed/(1+pow(elapsedTime,2))+ finalSpeed;
  velocity.normalize();
  velocity *= speed;
}


ofVec2f Kinematics::applyForce(ofVec3f _vector){
  acceleration += _vector;
}


void Kinematics::update(){
  //setVelocity();
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
