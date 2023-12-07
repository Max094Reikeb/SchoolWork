import argparse
import sys
from enum import Enum


class Operation(Enum):
    ADDITION = "addition"
    SOUSTRACTION = "soustraction"
    MULTIPLICATION = "multiplication"
    DIVISION = "division"


def display_result(name, result):
    """
    Fonction qui affiche à l'utilisateur le résultat du calcul.
    :param name: Le prénom de l'utilisateur.
    :param result: Le résultat du calcul.
    """
    print("Bonjour " + name + "\n\n")
    print("Le résultat de votre calcul est ", result)


def do_operation(operation, number1, number2):
    """
    Fonction qui effectue l'opération voulue de deux nombres.
    :param operation: Opération demandée.
    :param number1: Premier nombre de l'opération.
    :param number2: Deuxième nombre de l'opération.
    :return: Le résultat de l'opération.
    """
    match operation:
        case Operation.ADDITION:
            result = number1 + number2
        case Operation.SOUSTRACTION:
            result = number1 - number2
        case Operation.MULTIPLICATION:
            result = number1 * number2
        case Operation.DIVISION:
            try:
                result = number1 / number2
            except ZeroDivisionError as error:  # Gestion de la division par zéro.
                print(error)
                sys.exit()
        case _:
            print("Il y a un problème avec les opérations !")
            sys.exit(128)
    return result


def main():
    # Le parser détecte les arguments du programme
    parser = argparse.ArgumentParser(description="")
    parser.add_argument('-n', '--name', type=str, help='name of the person', required=True)
    parser.add_argument('-o', '--operation', type=Operation,
                        help='operation <addition | soustraction | multiplication | division>', required=True)
    parser.add_argument('-n1', '--number1', type=int, help='first number', required=True)
    parser.add_argument('-n2', '--number2', type=int, help='second number', required=True)
    args = parser.parse_args()

    # On vérifie que les arguments soient bien présents
    if args.name is None or args.operation is None or args.number1 is None or args.number2 is None or not (
            isinstance(args.number1, int)) or not (isinstance(args.number2, int)):
        print("Il y a un problème avec un/des argument(s) !")
        sys.exit(128)
    else:
        # On affiche le résultat de l'opération
        display_result(args.name, do_operation(args.operation, args.number1, args.number2))


if __name__ == '__main__':
    main()
