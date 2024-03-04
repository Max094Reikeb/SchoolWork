print("Entrez les valeurs réelles")
entreeReelle1 = float(input())
entreeReelle2 = float(input())
moyenneReelle = (entreeReelle1 + entreeReelle2) / 2
print(f"La moyenne de {entreeReelle1} et {entreeReelle2} est {moyenneReelle}")
print("Entrez les valeurs entières")
entreeEntiere1 = int(input())
entreeEntiere2 = int(input())
moyenneEntiere = (entreeEntiere1 + entreeEntiere2) // 2
resteEntier = (entreeEntiere1 + entreeEntiere2) % 2
print(f"La moyenne de {entreeEntiere1} et {entreeEntiere2} est {moyenneEntiere}")
print(f"Le reste du calcul de la moyenne est {resteEntier}")
