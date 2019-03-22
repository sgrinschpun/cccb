#include "StatsDisplay.h"


StatsDisplay::StatsDisplay(){
    stats.pMillis = ofGetElapsedTimeMillis();
    stats.pFrames = ofGetFrameNum();
}

void StatsDisplay::update(int nPart){
    stats.nParticles = nPart;
    if(ofGetElapsedTimeMillis() > stats.pMillis + 1000){
        stats.fps = ofGetFrameNum() - stats.pFrames;
        stats.pFrames = ofGetFrameNum();
        stats.pMillis = ofGetElapsedTimeMillis();
    }
    stats.useCPU = 100;
}
void StatsDisplay::display(){
    ofSetColor(127);
    ofDrawRectangle(0.65*ofGetWidth(), 0.85*ofGetHeight(), ofGetWidth()*0.4, ofGetHeight()*0.2);
    ofSetColor(255);
    ofDrawBitmapString("particles: "+ofToString(stats.nParticles), 0.7*ofGetWidth(), 0.9*ofGetHeight());
    ofDrawBitmapString("fps: "+ofToString(stats.fps), 0.7*ofGetWidth(), 0.925*ofGetHeight());
    ofDrawBitmapString("CPU: "+ofToString(stats.useCPU)+"%", 0.7*ofGetWidth(), 0.95*ofGetHeight());
}
