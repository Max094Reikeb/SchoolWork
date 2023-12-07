class Forme:
    def calculer_surface(self):
        pass


class Cercle(Forme):
    def __init__(self, r):
        self.rayon = r

    def calculer_surface(self):
        return 3.141592 * self.rayon * self.rayon

    def obtenir_rayon(self):
        return self.rayon


class Rectangle(Forme):
    def __init__(self, lon, lar):
        self.longueur = lon
        self.largeur = lar

    def calculer_surface(self):
        return self.longueur * self.largeur


if __name__ == "__main__":
    monCercle = Cercle(5.0)
    monRectangle = Rectangle(4.0, 6.0)

    mesFormes = [monCercle, monRectangle]

    for i in mesFormes:
        print(f"Surface de la forme: {i.calculer_surface()}")
