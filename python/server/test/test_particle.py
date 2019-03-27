import pytest
from phenomena.particles.models import QuantumUniverseParticle
from phenomena.particles.sources import ParticleDataSource, DecayLanguageFetcher
from phenomena.particles.transformations import TransformationChannels
from particletools.tables import *
from pylatexenc.latex2text import LatexNodes2Text



def test_particle():
    # for part in ['u', "ubar", "d", "dbar","c","cbar","s","sbar","b","bbar"]:
    #     this = QuantumUniverseParticle(part)
    #     print (this.transformtime)
    particle = QuantumUniverseParticle('Omega*_c0')
    print (particle.decay_channels)
    print (particle.mass)
    for item in particle.decay_channels[0][1]:
        print (ParticleDataSource.getName(item))
    particle2 = QuantumUniverseParticle('Omega_c0')
    print (particle2.type)
    print (particle2.mass)
    print (particle.name in ParticleDataSource.getExcludedParticles())
    print (TransformationChannels.from_decaylist(particle.decay_channels).all)
    #print (particle.transformation)
    #for channel in particle.transformation.selectType('Decay').channels.all:
    #    print (channel.names)
    #Omega*_c0
    #print (top.mass)

    #print (DecayLanguageFetcher.getHTMLName(particle.pdgid))
    #latex = DecayLanguageFetcher.getLatexName(particle.pdgid)
    #print (LatexNodes2Text().latex_to_text(latex))

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
