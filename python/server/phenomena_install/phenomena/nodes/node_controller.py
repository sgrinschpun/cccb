import time
from phenomena.particles import ServerParticle
from phenomena.connection.phenomena_message import IncomingMessage
from phenomena.nodes import get_save_node, ExecutableNode
from phenomena.nodes import JsonRemoteAudioVideoNode

from phenomena.particles.particle_action import ParticleAccumulatorNode, ParticleEntryNode

_node_controller = None

def getNodeController():
    global _node_controller
    if _node_controller == None: _node_controller = NodeController()
    return _node_controller

class IsParticleAddible():
    MINIMUM_TIME_BETWEEN_ADDS = 500
    MAX_NUMBER_OF_PARTICLES = 100
    current_milli_time = lambda: int(round(time.time() * 1000))
    
    def __init__(self, accumulator_node):
        self._last_added = IsParticleAddible.current_milli_time()
        self._last_difference = 0
        self._accumulator_node = accumulator_node
        
    def check(self):
        if not self._checkTime(): raise Exception("To add a new Particle you should wait {0}".format(IsParticleAddible.MINIMUM_TIME_BETWEEN_ADDS - self._last_difference))
        if not self._checkNumber(): raise Exception("To add a new Particle you should to have less than 100 Particles, they are {0}".format(self._accumulator_node.accumulatedParticles()))
        
    def _checkTime(self):
        new_last_added = IsParticleAddible.current_milli_time() 
        self._last_difference = new_last_added - self._last_added 
        if (self._last_difference) > IsParticleAddible.MINIMUM_TIME_BETWEEN_ADDS:
            self._last_added = new_last_added 
            return True
        else: 
            return False
    
    def _checkNumber(self):
        if(self._accumulator_node.accumulatedParticles() < IsParticleAddible.MAX_NUMBER_OF_PARTICLES): ret = True
        else: ret = False
        return ret
    
class NodeController(ExecutableNode):
    _commands = {'ADD': "_addParticle"}

    def __init__(self):
        self._root_node = ParticleEntryNode()
        self._audiovideonode = JsonRemoteAudioVideoNode()
        self._last_node = ParticleAccumulatorNode()
        _node = get_save_node()
        _node.setInitNode(self._root_node)
        self._root_node.setNextNode(self._audiovideonode)
        self._audiovideonode.setNextNode(self._last_node)
        #self._root_node.setNextNode(self._last_node)
        self._identifier = "node"
        self._is_particle_addible = IsParticleAddible(self._last_node)

    def _addParticle(self, **kwargs):
        self._is_particle_addible.check();
        particle_str = kwargs['particle_name']
        particle = ServerParticle.init(particle_str,**kwargs)
        self._root_node.addParticle(particle)

    def _purgeParticles(self, **kwargs):
        self._root_node.addParticle(particle)
        
    def findModule(self, module_path):
        if(module_path == self._identifier): return self
        else:
            next_module_path = module_path.split('.', 1)
            if(len(next_module_path) == 1): raise Exception("Module Not found Node Controller!")
            return self._root_node.findModule(next_module_path[1])

    def getIdentifier(self):
        return self._identifier

    def execute(self, incoming_message):
        assert isinstance(incoming_message, IncomingMessage)
        exec_method = getattr(self, NodeController._commands[incoming_message.command_name])
        exec_method(**incoming_message.params)



if __name__ == "__main__":
    node_controller = NodeController()
    particle = "pi+"
    node_controller._addParticle(particle = particle)
