import math
from phenomena.particles.transformations.transformationchannel import TransformationChannels
from phenomena.particles.transformations.types import Transformation
from phenomena.particles.sources import ParticleDataSource
from .hadronizationdata import HadronizationData

class Hadronization(Transformation):

    TARGET = None
    INPUT = ['u', "ubar", "d", "dbar","c","cbar","s","sbar","b","bbar"]

    def __init__(self, particle):
        self._particle = particle
        self._values = {}
        if  self._particle.name in Hadronization.INPUT:
            self._buildTransfValues()

    def _transformationChannels(self):
        hadronizationlist = HadronizationData.allParticles(self._particle.name)
        return TransformationChannels.from_decaylistNames(hadronizationlist)


    def getProbability(self, dt=1./60.):
        return 1
