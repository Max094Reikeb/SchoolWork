# Programme principal
# variables
#   entrée
#       chaine informations
#   sortie
#       tableau data
#       chaine nom
#       chaine prénom
#       chaine first_init
#       chaine last_init
# début
#   écrire("Entrez votre nom, prénom et date de naissance (format jj/mm/aaaa), séparés par un espace")
#   lire (informations)
#   data <- chaine 'informations' séparée par des espaces
#   nom <- data[0]
#   prenom <- data[1]
#   écrire("Votre prénom est: {prenom}")
#   écrire("Votre nom est: {nom}")
#   first_init <- prenom[0]
#   last_init <- nom[0]
#   si prenom contient "-":
#       first_init <- first_init + premier élément du tableau de la chaine 'prenom' séparée par un tiret
#   fin si
#   si nom contient "-":
#       last_init <- last_init + premier élément du tableau de la chaine 'nom' séparée par un tiret
#   écrire("Vos initiales sont: {first_init + last_init}")
#   écrire("Votre date de naissance est: {data[2]}")
# fin
print("Entrez votre nom, prénom et date de naissance (format jj/mm/aaaa), séparés par un espace")
informations = str(input())
data = informations.split(" ")
nom = data[0]
prenom = data[1]
print(f"Votre prénom est: {prenom}")
print(f"Votre nom est: {nom}")
first_init = prenom[0]
last_init = nom[0]
if "-" in prenom:
    first_init += prenom.split("-")[1][0]
if "-" in nom:
    last_init += nom.split("-")[1][0]
print(f"Vos initiales sont: {first_init + last_init}")
print(f"Votre date de naissance est: {data[2]}")
