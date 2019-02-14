from .osc import OSCMessageSender
from .osc import OSCPhenomenaServer
from .raw import RawMessageSender
from .raw import RawPhenomenaServer


class MODE:
    RAW = 1
    OSC = 2

_phenomena_server = {MODE.RAW: RawPhenomenaServer, MODE.OSC: OSCPhenomenaServer}
_message_sender = {MODE.RAW: RawMessageSender, MODE.OSC: OSCMessageSender}

def getMessageSender(mode):
    return _message_sender[mode]

def getPhenomenaServer(mode):
    return _phenomena_server[mode]