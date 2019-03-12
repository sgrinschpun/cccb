import random

class TimeController(object):
    '''
    Quark through hadronization -> 0.2
    Top, Mesons Barions -> rand (2)
    Leptons, Bosons -> rand(1,5)
    Neutron -> Rand(2,5)
    '''

    @staticmethod
    def getTime(particle):
        if particle.type in ['quark']:
            if particle.name in ['u', "ubar", "d", "dbar","c","cbar","s","sbar","b","bbar"]:
                time = 0.2
            else:
                time = random.uniform(0,2)
        elif particle.type in ['meson', 'baryon']:
            if particle.name in ['n0']:
                time = random.uniform(2,6)
            else:
                time = random.uniform(0,2)
        elif particle.type in ['lepton', 'boson']:
            time = random.uniform(1,5)
            try:
                if particle.virtuality==1:
                    time = 0.5
            except:
                pass

        return time
