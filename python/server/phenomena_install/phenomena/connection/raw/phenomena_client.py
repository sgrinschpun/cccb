import socket
from .commons import ClientPetitionHandler
from .commons import PORT
from phenomena.connection.interface import MessageSender
from phenomena.connection.phenomena_message import IncomingMessage, OutcomingMessage

class RawMessageSender(MessageSender):

    _command_id = 0

    @staticmethod
    def getCommandId():
        RawMessageSender._command_id += 1
        return RawMessageSender._command_id
    
    def __init__(self, host):
        # Create a TCP/IP socket
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # Connect the socket to the port where the server is listening
        server_address = (host, PORT)
        self._socket.connect(server_address)
        self._petition_handler = ClientPetitionHandler(self._socket)

    def sendMessage(self, module_path, command_name, *args, **kwargs):
        message = IncomingMessage.fromData(command_id = RawMessageSender.getCommandId(), command_name=command_name, module_path=module_path,
                                           params={'particle_name': kwargs.get('particle_name',0), 
                                                   'theta': kwargs.get('theta',0),
                                                   'phi': kwargs.get('phi',0),
                                                   'p':kwargs.get('p',None),
                                                   'E':kwargs.get('E',None)})
        self._petition_handler.sendPetition(message)


