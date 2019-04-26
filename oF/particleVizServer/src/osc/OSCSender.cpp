#include "OSCSender.h"

void OSCSender::setup(string hostIP, int port){
    sender.setup(hostIP, port);
}

void OSCSender::sendBigBangMessage(bool isBigBangOn){
    ofxOscMessage message;
    message.setAddress("/particle/bigbang");
    message.addBoolArg(isBigBangOn);
    sender.sendMessage(message);
}
void OSCSender::sendKillAppMessage(){
    ofxOscMessage message;
    message.setAddress("/killapp");
    sender.sendMessage(message);
}
