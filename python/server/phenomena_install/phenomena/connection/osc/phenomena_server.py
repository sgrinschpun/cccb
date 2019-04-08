import threading
import sys
import os
from phenomena.utils.log import get_logger
from phenomena.connection.interface import PhenomenaServer
from phenomena.connection.phenomena_message import IncomingMessage, OutcomingMessage
from pythonosc import dispatcher
from pythonosc import osc_server
from .commons import PORT, HOST
 
class OSCPhenomenaServer(PhenomenaServer):

    def __init__(self, node_controller):
        self._log = get_logger("Connection.OCSServer")
        self._log.info("Creating Server")
        self._dispatcher = dispatcher.Dispatcher()
        self._dispatcher.map("/*", self._attendPetition)
        self._server = osc_server.ThreadingOSCUDPServer((HOST, PORT), self._dispatcher)
        self._server_thread = threading.Thread(target = self._startServer)
        self._node_controller = node_controller

    def startServer(self):
        self._log.info("Starting Server")
        self._server_thread.start()

    def _startServer(self):
        self._log.info("Serving on {0}".format(self._server.server_address))
        self._server.serve_forever()

    def stopServer(self):
        self._server.shutdown()
        self._server_thread.join()
        self._server = osc_server.ThreadingOSCUDPServer((HOST, PORT), self._dispatcher)
        self._server_thread = threading.Thread(target = self._startServer)

    def _attendPetition(self, address, *args):
        try:
            split_modules_path = address[1:].split('/')
            module_path = ""
            command_name = ""
            params = {}
            #if(address.find("J/psi") != -1):
            #    module_path = "node" 
            #    command_name = "ADD"
            #    params["particle_name"] = "J/psi"
            #elif split_modules_path[0] == "ADD":
            #    module_path = "node" 
            #    command_name = "ADD"
            #    params["particle_name"] = split_modules_path[1]
            #elif split_modules_path[0] == "PURGE":
            #    module_path = "node.accumulator"
            #    command_name = "PURGE"
            if len(split_modules_path) == 1:
                if split_modules_path[0] == "ADD":
                    module_path = "node" 
                    command_name = "ADD"
                    params["particle_name"] = args[1]
                elif split_modules_path[0] == "PURGE":
                    module_path = "node.accumulator"
                    command_name = "PURGE"
            else:    
                command_name = split_modules_path[1]
                module_path = ".".join(split_modules_path[:-1])
                params = dict(zip(args[::2], args[1::2]))
            _id = params.pop("command_id", 0)
            new_message = IncomingMessage.fromData(command_id = _id, command_name = command_name, module_path = module_path, params = params)
            node = self._node_controller.findModule(new_message.module_path)
            node.execute(new_message)
            out_message = OutcomingMessage.okMessage(new_message, new_message.params)
            self._log.info(out_message)
        except Exception as ex:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            message = "Exception: Type: {0} Name: {1} Line: {2} Messsage: {3}".format(exc_type, fname, exc_tb.tb_lineno, str(ex))
            out_message = OutcomingMessage.errorMessage(new_message, message)
            self._log.exception(out_message)


"""
Json:
MESSAGE:
{
"MODULE_PATH": "x.y.z",
"COMMAND_NAME": CMD_NAME,
"COMMAND_ID": ID,
"PARAMS" : {}
}

RETURN:
{
"TYPE": OK//FAILED
"COMMAND_NAME": CMD_NAME,
"COMMAND_ID": ID,
"MODULE_PATH": "x.y.z",
"RETURN": message
}

[
{"CMD": "ADD",
"PARAMS": { "name":"pi+",
            "id": 1
            "mass":2E-16,
            "charge":3E-3,
            "lifetime":10E-12,
},

# COMMANDS_AVAILABLE:
{"CMD": "TRANSFORM",
"PARAMS": { "id": 1
                    "particles": [ { "name":"e-",
                       "id": 2
                      "mass":2E-16,
                      "charge":3E-3,
                      "lifetime":10E-12,
                    },
                      { "name":"mu+",
                       "id": 3
                      "mass":2E-16,
                      "charge":3E-3,
                      "lifetime":10E-12,
                    },

{"CMD": "REMOVE",
"PARAMS": { "id": 2},
],
]
"""
