
#http://scikit-hep.org/
from skhep.pdg import ParticleDataTable
from skhep.simulation import pdgid as PDGID
from skhep import units as u
from phenomena.particles.particle import Particle

import os
tbl = ParticleDataTable(os.path.join(os.path.dirname(__file__), "data/mass_width_2017.mcd"))

class SciKitHEPFetcher(object):

    @staticmethod
    def getName(pdgid):
        return tbl[pdgid].name

    @staticmethod
    def getPDGId(name):
        return tbl(name).id

    @staticmethod
    def getMass(pdgid):
        return tbl[pdgid].mass * u.GeV

    @staticmethod
    def getCharge(pdgid):
        return tbl[pdgid].charge

    @staticmethod
    def getTau(pdgid):
        tau = tbl[pdgid].lifetime
        if tau is None:
            tau = Particle.STABLE
        else:
            tau = tbl[pdgid].lifetime / u.nanosecond
        return tau

    @staticmethod
    def getType(pdgid):
        pdtype = ''
        if PDGID.isLepton(pdgid):
            pdtype = 'lepton'
        elif PDGID.isBaryon(pdgid):
            pdtype = 'baryon'
        elif PDGID.isMeson(pdgid):
            pdtype = 'meson'
        elif pdgid in [1,2,3,4,5,6,-1,-2,-3,-4,-5,-6]:
            pdtype = 'quark'
        elif pdgid in [21, 22, 23, 24, -24, 25, 37]:
            pdtype = 'boson'
        return pdtype

    @staticmethod
    def getSpin(pdgid):
        spin ={}
        spin['jSpin']= PDGID.jSpin(pdgid)  #Returns 2J+1, where J is the total angular momentum.
        spin['lSpin']= PDGID.lSpin(pdgid)  #Returns 2L+1, where L is the orbital angular momentum
        spin['sSpin']= PDGID.sSpin(pdgid)  #Returns 2S+1, where S is the spin.
        return spin

    @staticmethod
    def getWidth(pdgid):
        return tbl[pdgid].width * u.GeV

    @staticmethod
    def getCTau(pdgid):
        return tbl[pdgid].ctau

    @staticmethod
    def isLepton(pdgid):
        return PDGID.isLepton(pdgid)

    @staticmethod
    def isSUSY(pdgid):
        return PDGID.isSUSY(pdgid)
