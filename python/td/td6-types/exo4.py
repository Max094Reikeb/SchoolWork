# Programme principal
# variables
#   entrée
#       chaine chaine
#   interne
#       chaine space_chaine
# début
#   écrire("Entrez votre chaine: ")
#   lire (chaine)
#   si chaine == chaine à l'envers:
#       écrire("{chaine} est un palindrome")
#   sinon:
#       écrire("{chaine} n'est pas un palindrome")
#   fin si
# fin
chaine = input("Entrez votre chaine: ")
space_chaine = chaine.replace(" ", "")
if space_chaine == space_chaine[::-1]:
    print(f"{chaine} est un palindrome")
else:
    print(f"{chaine} n'est pas un palindrome")

# Exercice : 'a', 'b' et 'd' sont des palindromes, 'c' n'en est pas un.
