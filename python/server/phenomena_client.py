from phenomena.connection import OSCMessageSender
from phenomena.connection import RawMessageSender

HOST = '127.0.0.1'


class Phenomena:

    def addParticle(self, particle, **kwargs):
        params={'particle_name': particle, 'theta': kwargs.get('theta',0), 'phi': kwargs.get('phi',0), 'p':kwargs.get('p',0), 'E':kwargs.get('E',0)}
        received_message = self._sendMessage(module_path="node", command_name="ADD", **params)
        return received_message

    def purgeParticles(self):
        received_message = self._sendMessage(module_path="node.accumulator", command_name="PURGE")
        return received_message

    def _sendMessage(self, module_path, command_name, **kwargs):
        message_sender = RawMessageSender(HOST)
        return message_sender.sendMessage(module_path = module_path, command_name = command_name, **kwargs)


if __name__ == '__main__':
    import time
    import random
    phenomena = Phenomena()
    begin_time = time.time()

    for i in range(1):
        print(phenomena.addParticle("h0(H_1)"))
        # time.sleep()

    # loop_1 = random.randint(1, 10)
    # print("LOOP 1: {0}".format(loop_1))
    # for i in range(loop_1):
    #     loop_2 = random.randint(1, 10)
    #     print("LOOP 2: {0}".format(loop_2))
    #     for i in range(loop_2):
    #         print(phenomena.addParticle("Z0"))
    #         time.sleep(0.5)
    #     print(phenomena.purgeParticles())
    #     time.sleep(5)
    print("Total time: {0}".format(time.time() - begin_time))
