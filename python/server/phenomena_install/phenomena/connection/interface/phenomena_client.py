from abc import ABCMeta, abstractmethod

class MessageSender(metaclass = ABCMeta):

    @abstractmethod
    def sendMessage(self, module, command_name, *args, **kwargs):
        pass


