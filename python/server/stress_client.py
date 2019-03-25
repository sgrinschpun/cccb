import time
import random
from random import randint
from phenomena_client import Phenomena

PARTICLELIST = ['pi0','tau+','W+','h0(H_1)','J/psi','Omega_b-']

if __name__ == '__main__':
    phenomena = Phenomena()
    while True:
        print(phenomena.addParticle(random.choice(PARTICLELIST)))
        time.sleep(randint(0,5))
