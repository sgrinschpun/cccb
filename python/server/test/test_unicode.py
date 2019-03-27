import pytest
from phenomena.particles.models import QuantumUniverseParticle
from phenomena.particles.sources import ParticleDataSource, DecayLanguageFetcher

import warnings
warnings.filterwarnings("ignore", message="numpy.dtype size changed")
warnings.filterwarnings("ignore", message="numpy.ufunc size changed")

from decaylanguage.particle import Particle

unicode_dict = {
'mu': '\u03BC',
'^+': '\u207A'
}


def test_unicode():
 particle = QuantumUniverseParticle('mu+')
 print (particle.name)
 print (particle.pdgid)

 print (Particle.from_pdgid(particle.pdgid).html_name)

 print ('\u03A8\u207A')
 print (unicode_dict['mu']+unicode_dict['^+'])
 print (particle.name.replace('mu',unicode_dict['mu']))
 print (particle.name.replace('^+',unicode_dict['^+']))
 print (particle.name.replace('bla',unicode_dict['mu']))
 print (particle.name.replace('m',unicode_dict['mu']))
