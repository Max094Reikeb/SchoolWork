# Programme principal
# variables
#   entrée
#       réel a
#       réel b
#       réel c
#   sortie
#       réel determinant
#       réel racine1
#       réel racine2
# début
#   écrire("Entrez a")
#   lire (a)
#   écrire("Entrez b")
#   lire (b)
#   écrire("Entrez c")
#   lire (c)
#   determinant <- (b * b) - (4 * a * c)
#   si determinant < 0
#       écrire("L'équation {a}X^2 + {b}X + c possède un déterminant négatif, et n'a donc pas de solution réelle")
#   sinon si determinant == 0
#       racine1 <- (-b) / (2 * a)
#       écrire("L'équation {a}X^2 + {b}X + c possède un déterminant nul, et a donc 1 solution x1 = x2 = {racine1}")
#   sinon
#       racine1 <- (-b + sqrt(determinant)) / (2 * a)
#       racine2 <- (-b - sqrt(determinant)) / (2 * a)
#       écrire("L'équation {a}X^2 + {b}X + c possède un déterminant positif, et a donc 2 solutions : x1 = {racine1} et x2 = {racine2}")
#   fin si
# fin
from math import *

print("Entrez a")
a = float(input())
print("Entrez b")
b = float(input())
print("Entrez c")
c = float(input())
determinant = (b * b) - (4 * a * c)
if determinant < 0:
    print(f"L'équation {a}X^2 + {b}X + c possède un déterminant négatif, et n'a donc pas de solution réelle")
elif determinant == 0:
    racine1 = (-b) / (2 * a)
    print(f"L'équation {a}X^2 + {b}X + c possède un déterminant nul, et a donc 1 solution x1 = x2 = {racine1}")
else:
    racine1 = (-b + sqrt(determinant)) / (2 * a)
    racine2 = (-b - sqrt(determinant)) / (2 * a)
    print(f"L'équation {a}X^2 + {b}X + c possède un déterminant positif, et a donc 2 solutions : x1 = {racine1} et x2 = {racine2}")
