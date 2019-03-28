#!/usr/bin/env python
#-*- coding: utf-8 -*-

import pytest
from phenomena.particles.models import QuantumUniverseParticle
from phenomena.particles.sources import ParticleDataSource, DecayLanguageFetcher
from particle_unicode import unicodedict
#
# import warnings
# warnings.filterwarnings("ignore", message="numpy.dtype size changed")
# warnings.filterwarnings("ignore", message="numpy.ufunc size changed")
#
# from decaylanguage.particle import Particle
# from phenomena.particles.sources import ParticleDataSource,


def test_unicode():
    print (unicodedict['D+'])
    particle = QuantumUniverseParticle('B*+')
    print (particle.name)
    print (particle.symbolName)
 #print (DecayLanguageFetcher.getLatexName(particle.pdgid))
 #print (DecayLanguageFetcher.getHTMLName(particle.pdgid))
 #print (particle.symbolName)


    # EXCLUDED = ParticleDataSource.getExcludedParticles()
    # dict= {}
    # for item in ParticleDataSource.getParticleList():
    #     part = item[1].name
    #     if part not in EXCLUDED:
    #         dict[item[1].name]=""
    #
    #
    # with open('./particle_unicode.json', 'w') as f:
    #             f.write(json.dumps(dict,indent=2, sort_keys=True, ensure_ascii=False))


 # print (Particle.from_pdgid(particle.pdgid).html_name)
 #
 # print ('\u03A8\u207A')
 # print (unicode_dict['mu']+unicode_dict['^+'])
 # print (particle.name.replace('mu',unicode_dict['mu']))
 # print (particle.name.replace('^+',unicode_dict['^+']))
 # print (particle.name.replace('bla',unicode_dict['mu']))
 # print (particle.name.replace('m',unicode_dict['mu']))
