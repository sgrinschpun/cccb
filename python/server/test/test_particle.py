import pytest
from phenomena.particles.models import QuantumUniverseParticle
from phenomena.particles.sources import ParticleDataSource
from phenomena.particles.transformations import TransformationChannels
from particletools.tables import *



def test_particle():
    # for part in ['u', "ubar", "d", "dbar","c","cbar","s","sbar","b","bbar"]:
    #     this = QuantumUniverseParticle(part)
    #     print (this.transformtime)
    excluded =[]
    for item in ParticleDataSource.getParticleList():
        if ParticleDataSource.getType(item[1].name) == '':
            excluded.append(item[1].name)
    ['lepton', 'baryon', 'meson', 'quark', 'boson']
    print (excluded)

    print (ParticleDataSource.getExcludedParticles())

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
