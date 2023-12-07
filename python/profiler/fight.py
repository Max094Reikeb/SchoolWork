from pkm_types import Type
from pokemon import Attaque, Pokemon, Combat

# Créez quelques instances de la classe Attaque
charge = Attaque("Charge", 10, Type.NORMAL, True)
eclair = Attaque("Éclair", 40, Type.ELECTRIK, False)
pistolet_a_eau = Attaque("Pistolet à Eau", 30, Type.EAU, False)
coup_rapide = Attaque("Coup Rapide", 20, Type.COMBAT, True)

# Créez une instance de la classe Pokemon et apprenez-lui des attaques
pikachu = Pokemon("Pikachu", 25, Type.ELECTRIK)
pikachu.apprendre_attaque(charge)
pikachu.apprendre_attaque(eclair)

bulbizarre = Pokemon("Bulbizarre", 25, Type.PLANTE)
bulbizarre.apprendre_attaque(pistolet_a_eau)
bulbizarre.apprendre_attaque(coup_rapide)

# Affichez les attaques du Pokémon
pikachu.afficher_attaques()

combat = Combat(pikachu, bulbizarre)
combat.lancer_combat()
