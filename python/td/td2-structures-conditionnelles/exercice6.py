# Programme principal
# variables
#   entrée
#       réel nombreMasques
#   sortie
#       réel prixTotal
# début
#   écrire("Entrez le nombre de masques")
#   lire (nombreMasques)
#   prixTotal <- 0
#   si (nombreMasques >= 20)
#       prixTotal <- max(nombreMasques, 20) * 0,20
#   fin si
#   nombreMasques <- nombreMasques - 20
#   si (nombreMasques <= 0)
#       écrire("Le prix final est de {prixTotal}€")
#   fin si
#   si (nombreMasques >= 10)
#       prixTotal <- prixTotal + (max(nombreMasques, 10) * 0,15)
#   fin si
#   nombreMasques <- nombreMasques - 10
#   si (nombreMasques <= 0)
#       écrire("Le prix final est de {prixTotal}€")
#   fin si
#   prixTotal <- prixTotal + (nombreMasques * 0,10)
#   écrire("Le prix final est de {prixTotal}€")
# fin
print("Entrez le nombre de masques")
nombreMasques = float(input())
prixTotal = 0
if nombreMasques >= 20:
    prixTotal = max(nombreMasques, 20) * 0.20
nombreMasques = nombreMasques - 20
if nombreMasques <= 0:
    print(f"Le prix final est de {prixTotal}€")
if nombreMasques >= 10:
    prixTotal = prixTotal + (max(nombreMasques, 10) * 0.15)
nombreMasques = nombreMasques - 10
if nombreMasques <= 0:
    print(f"Le prix final est de {prixTotal}€")
prixTotal = prixTotal + (nombreMasques * 0.10)
print(f"Le prix final est de {prixTotal}€")
