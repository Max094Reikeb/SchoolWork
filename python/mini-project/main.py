# Mini Projet Python - Maxence BEKIER
import os

def grille_init():
    """Initialise la grille de puissance 4. Toutes les cases sont remplies par des zéros. Retourne le tableau initialisé."""
    grille = [[0] * 6 for _ in range(7)] # on crée un tableau de 6x7
    for rowIndex in range(6):
        for colIndex in range(7):
            # on prend deux index changeant de valeur entre 0 et les valeurs des lignes et colonnes pour pouvoir se déplacer dans tout le tableau
            grille[colIndex][rowIndex] = 0 # on donne donc à chaque case la valeur 0
    return grille # on retourne le tableau initialisé


def affiche_grille(tableau):
    """Affiche le tableau entré en argument."""
    print("\n| 1 | 2 | 3 | 4 | 5 | 6 | 7 |")
    print ("-----------------------------")
    for rowIndex in range(5, -1, -1):
        ligne = "| "
        for colIndex in range(7): # on se déplace sur toutes les colonnes
            ligne = ligne + str(tableau[colIndex][rowIndex]) + " | "
        print(f"{ligne}") # on affiche donc chaque ligne


def colonne_libre(tableau, colonne):
    """Vérifie si une colonne est libre. Prend en argument le tableau, ainsi que le numéro de la colonne. Retourne le booléen."""
    for rowIndex in range(6): # on se déplace sur les lignes
        if tableau[colonne][rowIndex] == 0:
            return True # si on rencontre un 0, alors la colonne est libre
    return False # si on rencontre pas de 0, alors pas la colonne est libre


def place_jeton(tableau, colonne, joueur):
    """Place un jeton dans une colonne. Prend en argument le tableau, la colonne et le joueur. Retourne le tableau modifié."""
    for rowIndex in range(6): # on se déplace sur les lignes
        if tableau[colonne][rowIndex] == 0:
            # dès qu'on trouve un emplacement libre, on met le pion
            tableau[colonne][rowIndex] = joueur
            break
    return tableau


def horizontale(tableau, joueur):
    """Vérifie si un joueur a aligné 4 pions dans une ligne. Prend en argument le tableau et le joueur. Retourne un booléen."""
    lignes = [""] * 6 # on fait 2 tableaux pour prendre les lignes et colonnes
    colonnes = [""] * 7
    for colIndex in range(7): # on se déplace sur la colonne
        # on ajoute dans le même tableau d'une dimension toutes les colonnes
        colonnes[colIndex] = colonnes[colIndex].join(str(tableau[colIndex]))
    for element in colonnes:
        for elementIndex in range(6):
            # on ajoute dans le même tableau d'une dimension toutes les lignes
            lignes[elementIndex] = lignes[elementIndex] + element[elementIndex]
    # on cherche si les tableaux contiennent les patternes "1111" ou "2222" pour indiquer la victoire du joueur
    for rowIndex in lignes:
        if "1111" in rowIndex and joueur == 1:
            return True
        if "2222" in rowIndex and joueur == 2:
            return True
    return False


def verticale(tableau, joueur):
    """Vérifie si un joueur a aligné 4 pions dans une colonne. Prend en argument le tableau et le joueur. Retourne un booléen."""
    colonnes = [""] * 7 # on fait 1 tableau pour prendre les colonnes
    for colIndex in range(7): # on se déplace sur la colonne
        # on ajoute dans le même tableau d'une dimension toutes les colonnes
        colonnes[colIndex] = colonnes[colIndex].join(str(tableau[colIndex]))
    # on cherche si les tableaux contiennent les patternes "1111" ou "2222" pour indiquer la victoire du joueur
    for item in colonnes:
        if "1111" in item and joueur == 1:
            return True
        if "2222" in item and joueur == 2:
            return True
    return False


def diagonale(tableau, joueur):
    """Vérifie si un joueur a aligné 4 pions en diagonale. Prend en argument le tableau et le joueur. Retourne un booléen."""
    for y in range(3):
        for x in range(4):
            # on se déplace sur la première partie du tableau avec la courte diagonale
            diag = ""
            for xx in range(4): # on se déplace sur le côté (la diagonale quoi)
                diag = diag + str(tableau[x+xx][y+xx])
            # on regarde si le patterne est présent et bon
            if diag == "1111" and joueur == 1:
                return True
            if diag == "2222" and joueur == 2:
                return True
    for y in range(3):
        for x in range(3, 7):
            # on se déplace sur la deuxième partie du tableau avec la longue diagonale
            diag = ""
            for xx in range(4):
                diag = diag + str(tableau[x-xx][y+xx])
            # on regarde si le patterne est présent et bon
            if diag == "1111" and joueur == 1:
                return True
            if diag == "2222" and joueur == 2:
                return True
    return False


def gagne(tableau, joueur):
    """Vérifie qu'un joueur a aligné 4 pions dans toutes les directions. Prend en argument le tableau et le joueur. Retourne un booléen."""
    return horizontale(tableau, joueur) or verticale(tableau, joueur) or diagonale(tableau, joueur) # on vérifie si le joueur a 4 pions alignés verticalement, horizontalement ou diagonalement


def tour_joueur(tableau, joueur):
    """Laisse le joueur poser un pion dans le tableau. Prend en argument le tableau et le joueur. Retourne le tableau modifié."""
    print(f"\nC'est à ton tour joueur {joueur}, dans quelle colonne veux-tu déposer ton pion ?")
    while 1: # boucle infinie qui ne sera cassée que quand on le voudra
        print(">>> ", end = "")
        colonne = int(input()) # on demande au joueur la colonne où il veut poser son pion
        if colonne_libre(tableau, colonne - 1): # on vérifie que la colonne est libre
            return place_jeton(tableau, colonne - 1, joueur) # on retourne la fonction qui place le jeton, et donc, le tableau modifié
            break # on peut casser la boucle
        else:
            print(f"\nLa colonne {colonne} n'est pas libre ! Choisis-en une autre...") # sinon, on lui dit que la colonne est pas libre, et la boucle recommence


def grille_pleine(tableau):
    """Vérifie que la grille soit pleine. Prend en argument le tableau. Retourne un booléen."""
    for rowIndex in range(6):
        for colIndex in range(7):
            # on se déplace dans tout le tableau avec les index
            if tableau[colIndex][rowIndex] == 0:
                return False # il ne suffit que d'un zéro pour dire que la grille n'est pas pleine
    return True


def egalite(tableau):
    """Vérifie s'il y a égalité entre les joueurs. Prend en argument le tableau. Retourne un booléen."""
    return grille_pleine(tableau) and not(gagne(tableau, 1)) and not(gagne(tableau, 2)) # on vérifie que la grille soit pleine et qu'aucun joueur n'aie gagné


def jouer(tableau):
    """Laisse les joueurs jouer chacun leur tour, avec vérification d'égalité et de victoire. Prend en argument le tableau."""
    while 1: # boucle infinie qui ne sera cassée que quand on le voudra
        os.system('clear')
        affiche_grille(tableau)
        tableau = tour_joueur(tableau, 1) # c'est le tour du joueur 1
        affiche_grille(tableau)
        if egalite(tableau): # on check pour l'égalité
            print("Il y a égalité !")
            break # égalité, on casse la boucle
        if gagne(tableau, 1): # on check pour la victoire du joueur 1
            print("Bravo joueur 1, tu as gagné !")
            break # victoire du j1, on casse la boucle
        tableau = tour_joueur(tableau, 2) # c'est le tour du joueur 2
        affiche_grille(tableau)
        if egalite(tableau): # on check pour l'égalité
            print("Il y a égalité !")
            break # égalité, on casse la boucle
        if gagne(tableau, 2): # on check pour la victoire du joueur 2
            print("Bravo joueur 2, tu as gagné !")
            break # victoire du j2, on casse la boucle


tableau = grille_init() # on initialise le tableau de jeu
jouer(tableau) # on lance la boucle de jeu
