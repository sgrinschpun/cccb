import pytest
from phenomena.particles.models import QuantumUniverseParticle
from phenomena.particles.sources import ParticleDataSource
from phenomena.particles.transformations import TransformationChannels



def test_particle():
    for part in ['u', "ubar", "d", "dbar","c","cbar","s","sbar","b","bbar"]:
        this = QuantumUniverseParticle(part)
        print (this.transformtime)


    #print (ParticleDataSource.getName(25))
    #print (ParticleDataSource.getName(22))

    # h = QuantumUniverseParticle('h0(H_1)')
    # print (h.mass)
    # for channel in h.transformation.selectType('Decay').channels.all:
    #     print (channel.names)

    #print (h.name)
    #print (h.pdgid)
    # list = ParticleDataSource.getDecayChannels(h.pdgid)
    # print (TransformationChannels.from_decaylist(list).all)
    #print (h.decay_channels)
    ##print (h.transformation.selectType('Decay').channels.all)

    # print (h.decay_channels)
    # print (h.transformation.allTypes[0].type)
    # print (h.transformation.allTypes[0].channels.all)
