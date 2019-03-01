from phenomena.connection import OSCMessageSender

HOST = '127.0.0.1'


class Phenomena:

    def addParticle(self, particle, **kwargs):
        params={'particle_name': particle, 'theta': kwargs.get('theta',0), 'phi': kwargs.get('phi',0), 'p':kwargs.get('p',0), 'E':kwargs.get('E',0)}
        received_message = self._sendMessage(module_path="node", command_name="ADD", **params)
        return received_message

    def _sendMessage(self, module_path, command_name, **kwargs):
        message_sender = OSCMessageSender(HOST)
        return message_sender.sendMessage(module_path = module_path, command_name = command_name, **kwargs)


if __name__ == '__main__':
    import time

    phenomena = Phenomena()
    begin_time = time.time()
    for i in range(1):
        print(phenomena.addParticle("e-"))
        # time.sleep()
    print("Total time: {0}".format(time.time() - begin_time))
