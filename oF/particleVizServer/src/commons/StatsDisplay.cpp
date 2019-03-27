#include "StatsDisplay.h"


StatsDisplay::StatsDisplay(){
    stats.pMillis = ofGetElapsedTimeMillis();
    stats.pFrames = ofGetFrameNum();
}

void StatsDisplay::update(int _nPartScreen, int _nPartAll){
    stats.nPartScreen = _nPartScreen;
    stats.nPartAll = _nPartAll;
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
    ofDrawBitmapString("particles on Screen: "+ofToString(stats.nPartScreen), 0.7*ofGetWidth(), 0.9*ofGetHeight());
    ofDrawBitmapString("particles all: "+ofToString(stats.nPartAll), 0.7*ofGetWidth(), 0.925*ofGetHeight());
    ofDrawBitmapString("fps: "+ofToString(stats.fps), 0.7*ofGetWidth(), 0.95*ofGetHeight());
    // ofDrawBitmapString("CPU: "+ofToString(stats.useCPU)+"%", 0.7*ofGetWidth(), 0.95*ofGetHeight());
}
