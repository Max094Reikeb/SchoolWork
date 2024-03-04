# Programme principal
# variables
#   entrée
#       entier chiffre
# début
#   écrire("Entrez votre chiffre")
#   lire (chiffre)
#   si chiffre == 0
#       écrire("zéro")
#   sinon si chiffre == 1
#       écrire("un")
#   sinon si chiffre == 2
#       écrire("deux")
#   sinon si chiffre == 3
#       écrire("trois")
#   sinon si chiffre == 4
#       écrire("quatre")
#   sinon si chiffre == 5
#       écrire("cinq")
#   sinon si chiffre == 6
#       écrire("six")
#   sinon si chiffre == 7
#       écrire("sept")
#   sinon si chiffre == 8
#       écrire("huit")
#   sinon si chiffre == 9
#       écrire("neuf")
#   sinon
#       écrire("Vous devez entrer un chiffre dans l'intervalle [0; 9] !")
#   fin si
# fin
print("Entrez votre chiffre")
chiffre = int(input())
if chiffre == 0:
    print("zéro")
elif chiffre == 1:
    print("un")
elif chiffre == 2:
    print("deux")
elif chiffre == 3:
    print("trois")
elif chiffre == 4:
    print("quatre")
elif chiffre == 5:
    print("cinq")
elif chiffre == 6:
    print("six")
elif chiffre == 7:
    print("sept")
elif chiffre == 8:
    print("huit")
elif chiffre == 9:
    print("neuf")
else:
    print("Vous devez entrer un chiffre dans l'intervalle [0; 9] !")
