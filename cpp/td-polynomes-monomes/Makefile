# Variables
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

# Fichiers sources et objets
SRC = main.cpp monome.cpp polynome.cpp
OBJ = $(SRC:.cpp=.o)

# Règle de compilation principale
programme : $(OBJ)
	$(CC) $(OBJ) -o programme

# Règles pour compiler chaque fichier .cpp en .o
%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean :
	rm -f $(OBJ) programme
