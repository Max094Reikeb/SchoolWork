# Programme principal
# variables
#   entrée
#       entier année
# début
#   écrire("Entrez votre année")
#   lire (année)
#   si année % 4 != 0
#       écrire("L'année {année} n'est pas bissextile !")
#   sinon
#       si année % 100 == 0 ET année % 400 != 0
#           écrire("L'année {année} n'est pas bissextile !")
#       sinon
#           écrire("L'année {année} est bissextile !")
#       fin si
#   fin si
# fin
print("Entrez votre année")
annee = int(input())
if annee % 4 != 0:
    print(f"L'année {annee} n'est pas bissextile")
else:
    if (annee % 100 == 0) & (annee % 400 != 0):
        print(f"L'année {annee} n'est pas bissextile")
    else:
        print(f"L'année {annee} est bissextile")
