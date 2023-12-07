class Cercle:
    def __init__(self, r):
        self.rayon = r

    def calculer_surface(self):
        return 3.141592 * self.rayon * self.rayon

    def obtenir_rayon(self):
        return self.rayon


class Rectangle:
    def __init__(self, longueur, largeur):
        self.longueur = longueur
        self.largeur = largeur

    def calculer_surface(self):
        return self.longueur * self.largeur

    def obtenir_longueur(self):
        return self.longueur

    def obtenir_largeur(self):
        return self.largeur


# Créer un cercle avec un rayon de 5
mon_cercle = Cercle(5.0)

# Accéder au rayon et calculer la surface
rayon = mon_cercle.obtenir_rayon()
surface = mon_cercle.calculer_surface()

print('Cercle avec un rayon de: ' + str(rayon))
print('Surface du cercle: ' + str(surface))

# Créer un rectangle avec une largeur et longueur donnée
longueur = int(input('Entrez la longueur du rectangle > '))
largeur = int(input('Entrez la largeur du rectangle > '))
mon_rectangle = Rectangle(longueur, largeur)

# Calcul de la surface
surface = mon_rectangle.calculer_surface()

print('Rectangle de longueur ' + str(longueur) + ' et largeur ' + str(largeur))
print('Surface du rectangle: ' + str(surface))
