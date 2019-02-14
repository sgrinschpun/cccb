import math, random

from skhep.math  import Kallen_function, Vector3D, LorentzVector
from skhep.units import MeV, GeV
from phenomena.particles.transformations.kinematics import KinematicsCalculations
from phenomena.particles.models.undercoverparticle import UndercoverParticle

class InelasticKinematics(KinematicsCalculations):
    '''
    We expect initialparticle and target to be a LorentzVector and outputparticles a list of LorentzVectors
    '''
    def __init__(self, initialparticle, target, finalparticles):
        self._target = target
        super(InelasticKinematics, self).__init__(initialparticle, finalparticles)

    def _set_finalState(self):
        self._finalState = LAB2BodyInelastic(self._initial, self._target, self._final).values

class LAB2BodyInelastic(object):
    def __init__(self,initialparticle, target, finalparticles):
        self._initialparticleLAB = initialparticle
        self._targetLAB = target
        self._finalparticlesLAB = finalparticles
        self._setCM()
        self._setLAB()

    def _setCM(self):
        self._setBoost()
        self._setS()
        self._setP()
        vector3Dlist = self._setVector3D(self._p)
        for id, particle in enumerate(self._finalparticlesLAB):
            particle.fourMomentum.setpxpypzm(vector3Dlist[id].x,vector3Dlist[id].y,vector3Dlist[id].z,particle.mass)

    def _setLAB(self):
        for particle in self._finalparticlesLAB:
            newfourMomentum = particle.fourMomentum.boost(-1*self._boostVector)
            particle.fourMomentum = newfourMomentum
            #print 'new', newfourMomentum


    def _setBoost(self):
        self._setBoostVector()
        self._initialparticleCM = self._initialparticleLAB.fourMomentum.boost(self._boostVector)
        self._targetCM = self._targetLAB.fourMomentum.boost(self._boostVector)

    def _setBoostVector(self):
        A = self._targetLAB.mass/(self._initialparticleLAB.mass*self._initialparticleLAB.fourMomentum.gamma)
        factor = 1/(A+1)
        self._boostVector = self._initialparticleLAB.fourMomentum.boostvector*factor

    def _setS(self):
        self._s = (self._initialparticleCM.e + self._targetCM.e)**2

    def _setP(self):
        m1 = self._finalparticlesLAB[0].mass
        m2 = self._finalparticlesLAB[1].mass
        self._p = math.sqrt( Kallen_function(self._s, m1**2, m2**2 ) /(4*self._s))
        #self._p = math.sqrt( Kallen_function(self._s, self._initialparticleLAB.mass**2, self._targetLAB.mass**2 ) /(4*self._s))

    def _setVector3D(self,p):
        theta = math.pi * random.random() # [0, math.pi]
        phi = 2*math.pi * random.random() # random.choice([-math.pi/2, -math.pi/2])
        vector1 = Vector3D.fromsphericalcoords(p,theta,phi)
        vector2= -1*vector1
        return [vector1, vector2]

    @property
    def values(self):
        return self._finalparticlesLAB