#!/bin/zsh
gcc -Wall -Wextra -L./lib -I./include -lSDL2 src/main.cpp -o main