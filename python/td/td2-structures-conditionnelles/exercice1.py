# Programme principal
# variables
#   entrée
#       entier a
#       entier b
# début
#   écrire("Entrez le premier entier")
#   lire (a)
#   écrire ("Entrez le deuxième entier")
#   lire (b)
#   si a < b
#       écrire("La plus petite valeur est {a}")
#   sinon
#       écrire("La plus petite valeur est {b}")
#   fin si
# fin
print("Entrez le premier entier")
a = int(input())
print("Entrez le deuxième entier")
b = int(input())
if a < b:
    print(f"La plus petite valeur est {a}")
else:
    print(f"La plus petite valeur est {b}")
