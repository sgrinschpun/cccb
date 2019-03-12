#include "Kinematics.h"

Kinematics::Kinematics(shared_ptr<ParticleData>& _particleData, ofPoint _position, ofVec3f _velocity): data(_particleData), position(_position), velocity(_velocity){

  Bfield.set(0,0,0.000001);
  acceleration.set(0,0,0);
  initSpeed = 30;
  finalSpeed = velocity.length();
  initTime = ofGetElapsedTimeMillis();
}

void Kinematics::setBforce(){
  float q = data->getCharge();
  float mass = data->getMass();
  Bforce = velocity.getCrossed(Bfield)*q/mass;
}

void Kinematics::setDragFroce(){
  float speed = velocity.length();
  float dragMagnitude = pow(speed,0.0001);
  //cout << "dragMagnitude" << dragMagnitude<< endl;
  DragForce = velocity * -1;
  //cout << "DragForce" << DragForce<< endl;
  DragForce.normalize();
  DragForce *= dragMagnitude;
  //cout << "DragForce" << DragForce<< endl;
}

void Kinematics::setVelocity(){
  float elapsedTime = ofGetElapsedTimeMillis() - initTime;
  float speed = initSpeed*exp(-pow(elapsedTime,2)/10) + finalSpeed;
  velocity.normalize();
  velocity *= speed;
}


ofVec3f Kinematics::applyForce(ofVec3f _vector){
  acceleration += _vector;
}


void Kinematics::update(){
  setVelocity();
  setBforce();
  applyForce(Bforce);
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;

}

ofPoint Kinematics::getPosition(){
  return position;
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
