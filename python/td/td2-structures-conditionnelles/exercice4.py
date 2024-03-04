# Programme principal
# variables
#   entrée
#       réel x
#       réel y
#   sortie
#       réel r
# début
#   écrire("Entrez x")
#   lire (x)
#   écrire("Entrez y")
#   lire (y)
#   r <- (4*x) + (2*y) + 6
#   si (r = 0)
#       écrire("Le point ({x};{y}) est sur la droite")
#   sinon si (r > 0)
#       écrire("Le point ({x};{y}) est au dessus de la droite")
#   sinon
#       écrire("Le point ({x};{y}) est en dessous de la droite")
#   fin si
# fin
print("Entrez x")
x = float(input())
print("Entrez y")
y = float(input())
r = (4*x) + (2*y) + 6
if r == 0:
    print(f"Le point ({x};{y}) est sur la droite")
elif r < 0:
    print(f"Le point ({x};{y}) est au dessus de la droite")
else:
    print(f"Le point ({x};{y}) est en dessous de la droite")
