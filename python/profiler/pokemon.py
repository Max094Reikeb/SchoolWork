class Attaque:
    def __init__(self, nom, degats, pkmn_type, physical):
        self.nom = nom
        self.degats = degats
        self.pkmn_type = pkmn_type
        self.physical = physical

    def is_physical(self):
        return self.physical


class Pokemon:
    def __init__(self, nom, hp, pkmn_type):
        self.nom = nom
        self.hp = hp
        self.pkmn_type = pkmn_type
        self.attaques = []

    def apprendre_attaque(self, attaque):
        if len(self.attaques) < 4:
            self.attaques.append(attaque)
        else:
            print(f"{self.nom} ne peut pas apprendre plus de 4 attaques.")

    def afficher_attaques(self):
        print(f"Attaques de {self.nom} :")
        for i, attaque in enumerate(self.attaques, start=1):
            print(f"{i}. {attaque.nom} (Dégâts : {attaque.degats})")


class Combat:
    def __init__(self, pokemon1, pokemon2):
        self.pokemon1 = pokemon1
        self.pokemon2 = pokemon2

    def lancer_combat(self):
        print(f"{self.pokemon1.nom} engage le combat avec {self.pokemon2.nom} !")
        while self.pokemon1.hp > 0 and self.pokemon2.hp > 0:
            self.tour_de_combat(self.pokemon1, self.pokemon2)
            if self.pokemon2.hp <= 0:
                print(f"{self.pokemon1.nom} a vaincu {self.pokemon2.nom} !")
                break
            self.tour_de_combat(self.pokemon2, self.pokemon1)
            if self.pokemon1.hp <= 0:
                print(f"{self.pokemon2.nom} a vaincu {self.pokemon1.nom} !")
                break

    def tour_de_combat(self, attaquant, defenseur):
        print(f"{attaquant.nom} attaque avec:")
        attaquant.afficher_attaques()
        choix_attaque = int(input(f"Choisissez une attaque (1-4) pour {attaquant.nom}: "))
        if 1 <= choix_attaque <= 4:
            attaque_utilisee = attaquant.attaques[choix_attaque - 1]
            print(f"{attaquant.nom} utilise {attaque_utilisee.nom} !")
            degats = attaque_utilisee.degats
            defenseur.hp -= degats
            print(f"{defenseur.nom} subit {degats} points de dégâts. Niveau de {defenseur.nom} : {defenseur.hp}")
        else:
            print("Choix invalide. Sélectionnez une attaque de 1 à 4.")
