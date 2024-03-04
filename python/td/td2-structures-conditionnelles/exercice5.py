# Programme principal
# variables
#   entrée
#       entier a
#       entier b
# début
#   écrire("Entrez le premier entier")
#   lire (a)
#   écrire("Entrez le second entier")
#   lire (b)
#   si (a > 0 ET b > 0) OU (a < 0 ET b < 0)
#       écrire("Le résultat est positif")
#   sinon si (a < 0 ET b > 0) OU (a > 0 ET b < 0)
#       écrire("Le résultat est négatif")
#   sinon
#       écrire("Le résultat est nul")
#   fin si
# fin
print("Entrez le premier entier")
a = int(input())
print("Entrez le second entier")
b = int(input())
if (a > 0 & b > 0) | (a < 0 & b < 0):
    print("Le résultat est positif")
elif (a < 0 & b > 0) | (a > 0 & b < 0):
    print("Le résultat est négatif")
else:
    print("Le résultat est nul")
