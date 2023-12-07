class Vehicule:
    def __int__(self):
        self.marque = ""

    def afficher_marque(self):
        print('Marque: ', self.marque)


class Voiture(Vehicule):
    def __init__(self):
        super().__init__()
        self.modele = ""

    def afficher_modele(self):
        print("Modèle: ", self.modele)


if __name__ == "__main__":
    # Créer un objet de la voiture
    ma_voiture = Voiture()
    # Initialiser les variables de la voiture
    ma_voiture.marque = "Honda"
    ma_voiture.modele = "Accord"
    # Afficher les variables de la voiture
    ma_voiture.afficher_marque()
    ma_voiture.afficher_modele()
    # Terminer le programme
    exit(0)
