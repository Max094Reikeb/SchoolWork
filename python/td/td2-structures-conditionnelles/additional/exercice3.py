# Programme principal
# variables
#   entrée
#       entier indice
# début
#   écrire("Entrez votre indice")
#   lire (indice)
#   si indice == 1
#       écrire("Micro tremblement de terre, non ressenti")
#   sinon si indice == 2
#       écrire("Très mineur, non ressenti mais détecté")
#   sinon si indice == 3
#       écrire("Mineur, causant rarement des dommages")
#   sinon si indice == 4
#       écrire("Léger, secousses notables d’objets à l’intérieur des maisons")
#   sinon si indice == 5
#       écrire("Modéré, légers dommages aux édifices bien construits")
#   sinon si indice == 6
#       écrire("Fort, destructeur dans des zones allant jusqu’à 180 km à la ronde si elles sont peuplées")
#   sinon si indice == 7
#       écrire("Majeur, dommages modérés à sévères dans des zones plus vastes")
#   sinon si indice == 8
#       écrire("Important, dommages sérieux dans des zones à des centaines de km à la ronde")
#   sinon si indice == 9
#       écrire("Dévastateur, dévaste des zones sur des millers de km à la ronde")
#   sinon
#       écrire("Vous devez entrer un indice dans l'intervalle [1; 9] !")
#   fin si
# fin
print("Entrez votre indice")
indice = int(input())
if indice == 1:
    print("un")
elif indice == 2:
    print("deux")
elif indice == 3:
    print("Mineur, causant rarement des dommages")
elif indice == 4:
    print("Léger, secousses notables d’objets à l’intérieur des maisons")
elif indice == 5:
    print("Modéré, légers dommages aux édifices bien construits")
elif indice == 6:
    print("Fort, destructeur dans des zones allant jusqu’à 180 km à la ronde si elles sont peuplées")
elif indice == 7:
    print("Majeur, dommages modérés à sévères dans des zones plus vastes")
elif indice == 8:
    print("Important, dommages sérieux dans des zones à des centaines de km à la ronde")
elif indice == 9:
    print("Dévastateur, dévaste des zones sur des miliers de km à la ronde")
else:
    print("Vous devez entrer un indice dans l'intervalle [1; 9] !")
