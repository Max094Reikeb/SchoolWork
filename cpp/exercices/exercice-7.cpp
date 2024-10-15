#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

typedef struct pos{
    int x;
    int y;
}Position;

enum Color: char { Blanche = 'b', Grise = 'g' };

class Case{
    private:
    Position pos;
    bool isPawnInside;
    Color color;
    public:
    void set(Position p, bool pawn, Color c) {
        pos = p;
        isPawnInside = pawn;
        color = c;
    }

    void print() {
        cout << "Couleur: " << color << ", position: " << pos.x << "," << pos.y << ", contient un pion? " << isPawnInside << endl;
    }

    Color getColor() {
        return color;
    }

    int getPosX() {
        return pos.x;
    }

    int getPosY() {
        return pos.y;
    }

    void setPos(int x, int y) {
        pos.x = x;
        pos.y = y;
    }
};

int main() {
    Case c1, c2;
    Position pos1, pos2;
    pos1.x = 3;
    pos2.x = 5;
    pos1.y = 2;
    pos2.y = 9;
    c1.set(pos1, false, Color::Blanche);
    c2.set(pos2, true, Color::Grise);
    c1.print();
    c2.print();
    return 0;
}
