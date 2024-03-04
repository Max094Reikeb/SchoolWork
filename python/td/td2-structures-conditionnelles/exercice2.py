# Programme principal
# variables
#   entrée
#       entier a
#   sortie
#       booléen isEven
# début
#   écrire("Entrez la valeur à définir")
#   lire (a)
#   isEven <- a % 2 == 0
#   si isEven est vrai
#       écrire("{a} est pair")
#   sinon
#       écrire("{a} est impair")
#   fin si
# fin
print("Entrez la valeur à définir")
a = int(input())
isEven = a % 2 == 0
if isEven:
    print(f"{a} est pair")
else:
    print(f"{a} est impair")
