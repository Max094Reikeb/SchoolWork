# Nom de l'exécutable
TARGET = jeu_de_dames

# Fichiers sources
SRC = main.cpp plateau.cpp jeu.cpp joueur.cpp piece.cpp minmax.cpp

# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Règle par défaut
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Règle pour nettoyer les fichiers objets et exécutables
clean:
	rm -f $(TARGET)
