import os
import sys

from phenomena.connection.phenomena_message import IncomingMessage, OutcomingMessage
from phenomena.utils.log import get_logger

PORT = 16180
HOST = '0.0.0.0'
DATASIZE = 5


class PetitionCommon():

    def __init__(self, conn, log):
        self._conn = conn
        self._log = log

    def _receiveData(self):
        try:
            str_size = self._receive(DATASIZE)
            size = int(str_size)
            return self._receive(size)
        except Exception as ex:
            self._log.exception("Failed receiving data: {0}".format(ex.message))

    def _send(self, msg):
        total_sent = 0
        message_length = len(msg)
        while total_sent < message_length:
            print("THis is the message: {0}".format(str(msg)))
            sent = self._conn.send(msg[total_sent:])
            if sent == 0:
                raise RuntimeError("socket connection broken")
            total_sent = total_sent + sent

    def _sendData(self, message):
        try:
            self._send(str(len(message)).zfill(5).encode('utf-8'))
            self._send(message)
        except Exception as ex:
            self._log.exception("Failed sending data: {0}".format(ex.message))

    def _receive(self, message_length):
        chunks = []
        bytes_recd = 0
        while bytes_recd < message_length:
            chunk = self._conn.recv(min(message_length - bytes_recd, 2048))
            if chunk == b'':
                raise RuntimeError("socket connection broken")
            chunks.append(chunk)
            bytes_recd = bytes_recd + len(chunk)
        return b''.join(chunks)


class ServerPetitionHandler(PetitionCommon):

    def __init__(self, conn, node_controller):
        self._log = get_logger("Connection.Server.RawOCSServer")
        PetitionCommon.__init__(self, conn, self._log)
        
        self._node_controller = node_controller

    def attendPetition(self):
        data = self._receiveData()
        self._treatData(data)

    def _treatData(self, data):
        try:
            new_message = IncomingMessage.deserialize(data)
        except Exception as ex:
            out_message = OutcomingMessage.errorSerializeMessage(ex.message)
            self._sendData(out_message.serialize())
        else:
            self._log.info("Received Command!")
            try:
                node = self._node_controller.findModule(new_message.module_path)
                node.execute(new_message)
                out_message = OutcomingMessage.okMessage(new_message, new_message.params)
                self._sendData(out_message.serialize())
            except Exception as ex:
                exc_type, exc_obj, exc_tb = sys.exc_info()
                fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
                message = "Exception: Type: {0} Name: {1} Line: {2} Messsage: {3}".format(exc_type, fname, exc_tb.tb_lineno, str(ex))
                print("exception!: {0}".format(message))
                out_message = OutcomingMessage.errorMessage(new_message, message)
                self._sendData(out_message.serialize())



class ClientPetitionHandler(PetitionCommon):

    def __init__(self, conn):
        self._log = get_logger("Connection.Client.Petition")
        PetitionCommon.__init__(self, conn, self._log)
        

    def sendPetition(self, incoming_message):
        assert isinstance(incoming_message, IncomingMessage)
        self._sendData(incoming_message.serialize())
        data = self._receiveData()
        return OutcomingMessage.deserialize(data)
