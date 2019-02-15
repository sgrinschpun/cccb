from phenomena.connection.interface import MessageSender
from .commons import PORT
from pythonosc import osc_message_builder
from pythonosc import udp_client
from pythonosc import osc_bundle_builder

class OSCMessageSender(MessageSender):

    _command_id = 0

    @staticmethod
    def getCommandId():
        OSCMessageSender._command_id += 1
        return OSCMessageSender._command_id
    
    def __init__(self, host, port = PORT):
        self._client = udp_client.SimpleUDPClient(host, port)

    def sendMessage(self, module_path, command_name, *args, **kwargs):
        module_path = "/{0}".format(module_path.replace(".", "/"))
        bundle = osc_bundle_builder.OscBundleBuilder(osc_bundle_builder.IMMEDIATELY)
        msg = osc_message_builder.OscMessageBuilder(address = module_path)
        self._addArgument(msg, "command_id", OSCMessageSender.getCommandId())
        self._addArgument(msg, "command_name", command_name)
        for name, value in kwargs.items():
            self._addArgument(msg, name, value)
        bundle.add_content(msg.build())
        bundle = bundle.build()
        self._client.send(bundle)   

    def _addArgument(self, msg, name, value):
        msg.add_arg(name)
        msg.add_arg(value)

