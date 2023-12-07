import argparse


def display_name(name):
    """
    Fonction qui affiche le message "Hello", suivi du nom entré en paramètre
    :param name: Nom à afficher
    """
    print("Hello " + name)


def main():
    # Le parser pour détecter les arguments lors de l'éxecution du programme
    parser = argparse.ArgumentParser(description="")
    parser.add_argument('-n', '--name', type=str, help='name of the person')
    args = parser.parse_args()

    # On regarde si l'argument du nom est donné ou non
    if args.name is None:
        # S'il n'est pas donné, on fait un point d'entrée custom
        name = input('Enter the name: ')
        display_name(name)
    else:
        # S'il est donné, on appelle la fonction qui affiche le prénom directement
        display_name(args.name)


if __name__ == '__main__':
    main()
