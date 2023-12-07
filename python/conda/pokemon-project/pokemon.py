from enum import Enum

'''
import requests

url = "https://api-pokemon-fr.vercel.app/api/v1/pokemon"
headers = {
    "User-Agent": "RobotPokemon",
    "From": "adresse[at]domaine[dot]com",
    'Content-type': 'application/json'
}

response = requests.get(url, headers=headers)

if response.status_code == 200:
    data = response.json()
    #print(data)
else:
    print("La requête a échoué avec le code d'état:", response.status_code)

def get_random_pokemon():
    url = "https://api-pokemon-fr.vercel.app/api/v1/pokemon"
    response = requests.get(url)
    all_pokemon = response.json()

    print(all_pokemon[0].keys())
    random_pokemon = random.choice(all_pokemon)
    print(random_pokemon['types'])

    details_url = f"https://api-pokemon-fr.vercel.app/api/v1/pokemon/{random_pokemon['pokedexId']}"
    details_response = requests.get(details_url)
    details_data = details_response.json()

    random_attaques = random.sample(details_data['attaques'], min(len(details_data['attaques']), 4))
    attaques_objects = [Attaque(nom=move['name'], base_def=10, is_spe=False, type_=Types.EAU) for move in random_attaques]

    niveau = random.randint(1, 100)
    att = random.randint(5, 200)
    att_spe = random.randint(5, 200)
    deff = random.randint(5, 200)
    deff_spe = random.randint(5, 200)
    vit = random.randint(5, 200)
    hp = random.randint(5, 200)

    return Pokemon(nom=details_data['name'], type_=None, niveau=niveau, att=att, deff=deff,
                   att_spe=att_spe, deff_spe=deff_spe, vit=vit, hp=hp, attaques=attaques_objects)
'''

Type = Enum('Type',
            ['ACIER', 'COMBAT', 'DRAGON', 'EAU', 'ELECTRIK', 'FEU', 'FEE', 'GLACE', 'INSECTE', 'NORMAL', 'PLANTE',
             'POISON', 'PSY', 'ROCHE', 'SOL', 'SPECTRE', 'TENEBRES', 'VOL'])


class Attaque:
    def __init__(self, nom, degats, Pkmn_type):
        self.nom = nom
        self.degats = degats
        self.Pkmn_type = Pkmn_type


class Pokemon:
    def __init__(self, nom, niveau, Pkmn_type):
        self.nom = nom
        self.niveau = niveau
        self.Pkmn_type = Pkmn_type
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
        while self.pokemon1.niveau > 0 and self.pokemon2.niveau > 0:
            self.tour_de_combat(self.pokemon1, self.pokemon2)
            if self.pokemon2.niveau <= 0:
                print(f"{self.pokemon1.nom} a vaincu {self.pokemon2.nom} !")
                break
            self.tour_de_combat(self.pokemon2, self.pokemon1)
            if self.pokemon1.niveau <= 0:
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
            defenseur.niveau -= degats
            print(f"{defenseur.nom} subit {degats} points de dégâts. Niveau de {defenseur.nom} : {defenseur.niveau}")
        else:
            print("Choix invalide. Sélectionnez une attaque de 1 à 4.")


# Créez quelques instances de la classe Attaque
charge = Attaque("Charge", 10, Type.NORMAL)
eclair = Attaque("Éclair", 40, Type.ELECTRIK)
pistolet_a_eau = Attaque("Pistolet à Eau", 30, Type.EAU)
coup_rapide = Attaque("Coup Rapide", 20, Type.COMBAT)

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
