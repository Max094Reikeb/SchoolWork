import unittest
from pokemon import Attaque
from pkm_types import Type


class TestAttaque(unittest.TestCase):
    def is_physical(self):
        charge = Attaque("Charge", 10, Type.NORMAL, True)
        eclair = Attaque("Éclair", 40, Type.ELECTRIK, False)
        pistolet_a_eau = Attaque("Pistolet à Eau", 30, Type.EAU, False)
        coup_rapide = Attaque("Coup Rapide", 20, Type.COMBAT, True)
        self.assertTrue(charge.is_physical())
        self.assertFalse(eclair.is_physical())
        self.assertFalse(pistolet_a_eau.is_physical())
        self.assertTrue(coup_rapide.is_physical())


if __name__ == '__main__':
    unittest.main()
