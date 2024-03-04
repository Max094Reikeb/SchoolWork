#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import getopt
import os
import sys
import turtle
import yaml


def createLSystem(level, axiome, regle_a, regle_b):
    """
    Crée le système (itération + axiome)

    :param level: Niveau de règle
    :type level: int
    :param axiome: Axiome
    :type axiome: str
    :param regle_a: Règle sur a
    :type regle_a: str
    :param regle_b: Règle sur b
    :type regle_b: str
    :return: L'axiome final
    :type: str
    """
    startString = axiome
    endString = ""
    for i in range(level):
        endString = processString(startString, regle_a, regle_b)  # Modifie l'axiome pour remplacer les lettres
        startString = endString
    return endString


def processString(oldStr, regle_a, regle_b):
    """
    Regarde l'axiome entré et applique les règles pour chaque caractère

    :param oldStr: Axiome d'entrée
    :type oldStr: str
    :param regle_a: Règle sur a
    :type regle_a: str
    :param regle_b: Règle sur b
    :type regle_b: str
    :return: L'axiome final pour le niveau correspondant
    :type: str
    """
    newStr = ""
    for ch in oldStr:
        newStr = newStr + applyRules(ch, regle_a, regle_b)  # On applique les règles pour chaque caractère
    return newStr


def applyRules(ch, regle_a, regle_b):
    """
    Applique les règles selon le caractère (a, b ou autre)

    :param ch: Le caractère d'entrée
    :type ch: str
    :param regle_a: Règle sur a
    :type regle_a: str
    :param regle_b: Règle sur b
    :type regle_b: str
    :return: Le caractère / string correspondant
    :type: str
    """
    newstr = ""
    if ch == 'a':
        newstr = regle_a  # Règle sur a
    elif ch == 'b':
        newstr = regle_b  # Règle sur b
    else:
        newstr = ch  # Pas de règle donc on garde le caractère
    return newstr


def applyColor(aTurtle):
    """
    Gère les couleurs. Noir -> rouge -> vert -> bleu -> noir et ainsi de suite

    :param aTurtle: La tortue
    """
    a, b = aTurtle.color()
    if a == "red":
        aTurtle.color("green")
    elif a == "green":
        aTurtle.color("blue")
    elif a == "blue":
        aTurtle.color("black")
    else:
        aTurtle.color("red")


def drawLsystem(aTurtle, instructions, angle, distance):
    """
    Dessine les lignes selon le caractère

    :param aTurtle: La tortue
    :param instructions: Axiome d'entrée
    :type instructions: str
    :param angle: Angle d'entrée
    :type angle: int
    :param distance: Longueur du trait
    :type distance: int
    """
    stack = []

    for cmd in instructions:
        if cmd == 'a':  # Avance
            aTurtle.forward(distance)
        elif cmd == 'b':  # Recule
            aTurtle.backward(distance)
        elif cmd == '+':  # Tourne à droite
            aTurtle.right(angle)
        elif cmd == '-':  # Tourne à gauche
            aTurtle.left(angle)
        elif cmd == '*':  # Tourne à 180°
            aTurtle.left(180)
        elif cmd == '[':  # Sauvegarde les coordonnées
            coordinate = (aTurtle.xcor(), aTurtle.ycor())
            stack.append(coordinate)
        elif cmd == ']':  # Se téléporte aux dernières coordonnées sauvegardées
            tp = stack.pop()
            aTurtle.setpos(tp)
        elif cmd == 'c':  # Change la couleur du trait
            applyColor(aTurtle)
        elif cmd == '{':  # Remplit la forme dessinée après
            aTurtle.begin_fill()
        elif cmd == '}':  # Arrête de remplir la forme dessinée
            aTurtle.end_fill()


def readFile(file):
    """
    Lit de fichier de configuration

    :param file: Fichier de configuration
    :type file: str
    :return: L'axiome, les règles sur a et b, l'angle, la taille et le niveau
    :type: tuple[str, str, str, int, int, int]
    """
    with open(file, 'r') as stream:  # On ouvre le fichier config
        data_loaded = yaml.safe_load(stream)
        axiome = data_loaded['axiome']
        regle_a = data_loaded['regles']['a']
        regle_b = data_loaded['regles']['b']
        angle = data_loaded['angle']
        taille = data_loaded['taille']
        niveau = data_loaded['niveau']

        if axiome == "" or regle_a == "" or regle_b == "" or angle == 0 or taille == 0 or niveau == 0:
            print("Erreur: le fichier que vous avez entré contient des valeurs invalides.\n")
            return
        return axiome, regle_a, regle_b, angle, taille, niveau


def saveAndPrint(save, printed, f):
    """
    Sauvegarde et affiche un string dans le fichier fournis

    :param save: String à sauvegarder
    :type save: str
    :param print: String à envoyer dans la console
    :type print: str
    :param f: Fichier où le premier string est sauvegardé
    :type f: TextIO
    """
    print(printed)
    f.write(save)


def displayCode(axiom, taille, angle, outputfile):
    """
    Affiche le code executé pour le programme et le sauvegarde dans le fichier de sortie

    :param axiom: Axiome d'entrée
    :type axiom: str
    :param taille: Longueur du trait
    :type taille: int
    :param angle: Angle d'entrée
    :type angle: int
    :param outputfile: Fichier de sortie
    :type outputfile: str
    """
    f = open(outputfile, "w")
    for ch in axiom:
        if ch == 'a':
            saveAndPrint("pd();fd({});\n".format(taille), "pd();fd({});".format(taille), f)
        elif ch == 'b':
            saveAndPrint("pu();fd({});\n".format(taille), "pu();fd({});".format(taille), f)
        elif ch == '+':
            saveAndPrint("right({});\n".format(angle), "right({});".format(angle), f)
        elif ch == '-':
            saveAndPrint("left({});\n".format(angle), "left({});".format(angle), f)
        elif ch == '*':
            saveAndPrint("right(100);\n", "right(100);", f)
        elif ch == '[':
            saveAndPrint("savePos();\n", "savePos();", f)
        elif ch == ']':
            saveAndPrint("loadSavedPos();\n", "loadSavedPos();", f)
        elif ch == 'c':
            saveAndPrint("color(next);\n", "color(next);", f)
        elif ch == '{':
            saveAndPrint("startFill();\n", "startFill();", f)
        elif ch == '}':
            saveAndPrint("endFill();\n", "endFill();", f)
    f.close()


def usage():
    """
    Affiche l'usage de l'appel du script python
    """
    print('python3 main.py -i <inputfile> -o <outputfile>')


def getFiles(opts):
    """
    Lit les paramètres d'entrée (-i et -o)

    :param opts: Paramètres d'entrée (-i <inputfile> et -o <outputfile>)
    :type opts: list
    :return: Retourne le fichier d'entrée et de sortie
    :type: str, str
    """
    inputfile = ""
    outputfile = ""

    for opt, arg in opts:
        if opt in ("-h", "--help"):
            usage()
            sys.exit(2)
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg
    if inputfile == "" or not inputfile.endswith(".yaml") or not os.path.isfile(inputfile):
        print("Le fichier d'entrée est invalide, vide ou inexistant.\nVeuillez vérifier qu'il est dans le même "
              "répertoire que le fichier principal, et réessayez.")
        sys.exit(2)
    if outputfile == "" or not outputfile.endswith(".txt") or not os.path.isfile(outputfile):
        print("Le fichier de sortie est invalide, vide ou inexistant.\nVeuillez vérifier qu'il est dans le même "
              "répertoire que le fichier principal, et réessayez.")
        sys.exit(2)

    return inputfile, outputfile


def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hi:o:", ["ifile=", "ofile="])
    except getopt.GetoptError as err:
        print(err)
        usage()
        sys.exit(2)

    inputfile, outputfile = getFiles(opts)  # Obtient les fichiers d'entrée et de sortie

    axiome, regle_a, regle_b, angle, taille, niveau = readFile(inputfile)  # Obtient les valeurs du fichier d'entrée
    inst = createLSystem(niveau, axiome, regle_a, regle_b)  # Crée l'entrée avec l'axiome et le niveau
    t = turtle.Turtle()  # Crée la tortue
    wn = turtle.Screen()  # Mets en place l'écran

    t.up()  # Mets la tortue en position initiale
    t.back(200)
    t.down()
    t.speed(0)
    displayCode(inst, taille, angle, outputfile)  # Affiche le code obtenu
    drawLsystem(t, inst, angle, taille)  # Dessine l'image avec la tortue, l'axiome, l'angle et la taille fournis
    wn.exitonclick()


if __name__ == "__main__":
    main()
