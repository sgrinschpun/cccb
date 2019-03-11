#!/usr/bin/env python

from __future__ import print_function

__author__ = "Cristobal Pio"
__license__ = "GPL"
__version__ = "0.1"
__email__ = "cgarcia@ifae.es"
__status__ = "Development"

import abc
from threading import Timer, Lock

from .particle import Particle
from .server_particle import ServerParticle
from phenomena.nodes import get_save_node, ConfigurableNode
from phenomena.utils import get_logger
from phenomena.connection.phenomena_message import IncomingMessage

def voidDecay(particle, new_particles):
    log = get_logger("Phenomena.accumulator")
    log.info("Silently Decaying particle")

class ParticleDecayTimer:
    def __init__(self, particle, transform_callback):
        self._log = get_logger("Phenomena.accumulator")
        self._transformCallback = transform_callback
        self._particle = particle
        self._particle.start(self._particleTransform)

    def _particleTransform(self):
        new_particles = self._particle.transformation.output   #changed
        self._transformCallback(self._particle, new_particles)

    def invalidateDecay(self):
        self._log.info("Invalidating Particle")    
        self._transformCallback = voidDecay
        
    def getParticle(self):
        return self._particle

class ParticleAction(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def addParticle(self, particle):
        pass

    @abc.abstractmethod
    def removeParticle(self, particle):
        pass

    @abc.abstractmethod
    def transformParticle(self, particle, new_particles):
        pass
    
    @abc.abstractclassmethod
    def purgeParticles(self):
        pass

class ParticleActionNodeEnd(ParticleAction, ConfigurableNode):


    def __init__(self):
        self._node = get_save_node()

    def findModule(self, module_path):
        if (module_path == self.getIdentifier()):
            return self
        raise Exception("Node End! Module Not found!: {0} {1}".format(self.getIdentifier(), module_path))

    def setNextNode(self, n_node):
        self._node.setNextNode(n_node)

    def setPastNode(self, p_node):
        self._node.setPastNode(p_node)

class ParticleActionNodeChain(ParticleAction, ConfigurableNode):

    def __init__(self):
        self._node = get_save_node()

    def findModule(self, module_path):
        if(module_path == self.getIdentifier()): return self
        else: return self._node.getNextNode(self).findModule(module_path)

    def setNextNode(self, n_node):
        self._node.setNextNode(n_node)

    def setPastNode(self, p_node):
        self._node.setPastNode(p_node)

# Fixed Particles Nodes

class ParticleAccumulatorNode(ParticleActionNodeEnd):
    _commands = {'PURGE': "_purgeParticles"}
    def __init__(self):
        ParticleActionNodeEnd.__init__(self)
        self._particles_available = []
        self._transform_lock = Lock()
        self._log = get_logger("Phenomena.accumulator")
        self._purge_cycle = False
        self._init_purge = False

    # Here Particles are accumulated and waiting to decay
    def addParticle(self, particle):
        assert issubclass(type(particle), Particle)
        self._log.info("Accumulating particle: {0}".format(particle.name))
        self._particles_available.append(ParticleDecayTimer(particle, self._transformedParticle))

    def removeParticle(self, particle):
        assert issubclass(type(particle), Particle)
        rm_particles_timer = [particle_timer for particle_timer in self._particles_available if particle_timer.getParticle() == particle]
        for rm_particle_timer in rm_particles_timer:
            self._log.info("removing: {0}".format(rm_particle_timer.getParticle().name))
            self._particles_available.remove(rm_particle_timer)
        self._log.info("Values inside: {0}".format(len(self._particles_available)))

    def transformParticle(self, particle, new_particles):
        assert issubclass(type(particle), Particle)
        assert isinstance(new_particles, list)
        for new_particle in new_particles:
            self.addParticle(new_particle)
        self.removeParticle(particle)

    def _transformedParticle(self, particle, new_particles):
        if self._init_purge: return
        self._transform_lock.acquire()
        tr_new_particles = []
        try:
            self._log.info("Particle: {0}".format(particle.name)),
            self._log.info("Will transform through: : {0}".format(particle.transformation.selectedType.type)),
            self._log.info("Will transform in: "),
            for idx, new_particle in enumerate(new_particles):
                self._log.info("New particle {0}:  {1}".format(idx+1,new_particle.name))
                tr_new_particles.append(ServerParticle.fromparticle(new_particle, parent = particle.id))
            for new_particle in new_particles: self._log.info("{0}, {1}, {2}, {3}".format(new_particle.name, new_particle.p, new_particle.phi, new_particle.theta))
            self._node.getNextNode(self).transformParticle(particle, tr_new_particles)
        finally:
            self._transform_lock.release()
    
    "Return the number of particules accumulated"
    def accumulatedParticles(self):
        return len(self._particles_available)
    
    def _purgeParticles(self):
        self._init_purge = True
        self._purge_cycle = True
        self.purgeParticles()
        self._init_purge = False
    
    def purgeParticles(self):
        if self._purge_cycle:
            self._purge_cycle = False
            try:
                #map(lambda x: x.invalidateDecay(), self._particles_available)
                for particle_decay in self._particles_available: particle_decay.invalidateDecay()
                self._particles_available = []
                self._node.getNextNode(self).purgeParticles()
            except Exception as ex:
                self._log.error("Error!: {0}".format(ex.message))
            finally:
                pass
    
#def findModule(self, module_path):
#    if (module_path == self._identifier):
#        return self
#    else:
#        next_module_path = module_path.split(' ', 1)
#        if (len(next_module_path) == 1): raise Exception("Module Not found!")
#        self._root_node.findModule(next_module_path[1])

    def getIdentifier(self):
        return "accumulator"

    def execute(self, incoming_message):
        assert isinstance(incoming_message, IncomingMessage)
        exec_method = getattr(self, ParticleAccumulatorNode._commands[incoming_message.command_name])
        exec_method(**incoming_message.params)

class ParticleEntryNode(ParticleActionNodeChain):

    def __init__(self):
        super(ParticleActionNodeChain, self).__init__()
        self._node = get_save_node()

    def addParticle(self, particle):
        assert issubclass(type(particle), Particle)
        self._node.getNextNode(self).addParticle(particle)

    def removeParticle(self, particle):
        assert issubclass(type(particle), Particle)

    def transformParticle(self, particle, new_particles):
        assert issubclass(type(particle), Particle)
        assert isinstance(new_particles, list)
        self._node.getNextNode(self).transformParticle(particle, new_particles)

    def purgeParticles(self):
        self._node.getNextNode(self).purgeParticles()
    
    def getIdentifier(self):
        return "entry"

    def setNextNode(self, n_node):
        self._node.setNextNode(self, n_node)

    def setPastNode(self, p_node):
        self._node.setPastNode(self, p_node)

    def execute(self, incoming_message):
        pass

if __name__ == '__main__':
    pass
