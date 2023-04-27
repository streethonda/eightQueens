#pragma once

#include <vector>
#include <iostream>
#include <string>

class Queen {
public:
    int row;
    int col;

    Queen(int r, int c);
};

class Board {
public:
    std::vector<Queen> queens;

    void placeQueen(int row, int col);
    void removeQueen();
    bool isSafe(int row, int col);
    bool placeQueens(int col);
    void display();
};
