# Programme principal
# variables
#   entrée
#       réel note
# début
#   écrire("Entrez votre note")
#   lire (note)
#   si note >= 0 ET note <= 6
#       écrire("Ajourné")
#   sinon si note > 6 ET note < 10
#       écrire("Rattrapage")
#   sinon si note >= 10 ET note <= 20
#       écrire("Admis")
#   sinon
#       écrire("Erreur: votre note n'est pas dans l'intervalle [0, 20]")
#   fin si
# fin
print("Entrez votre note")
note = float(input())
if note >= 0.0 & note <= 6.0:
    print("Ajourné")
elif note > 6.0 & note < 10.0:
    print("Rattrapage")
elif note >= 10.0 & note <= 20.0:
    print("Admis")
else:
    print("Erreur: votre note n'est pas dans l'intervalle [0, 20]")
