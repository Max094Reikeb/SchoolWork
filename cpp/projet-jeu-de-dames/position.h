#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    bool operator==(const Position& other) const { return x == other.x && y == other.y; }

private:
    int x, y;
};

#endif
