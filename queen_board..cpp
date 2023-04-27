#include "queen_board.h"

Queen::Queen(int r, int c) {
    row = r;
    col = c;
}

void Board::placeQueen(int row, int col) {
    queens.push_back(Queen(row, col));
}

void Board::removeQueen() {
    queens.pop_back();
}

bool Board::isSafe(int row, int col) {
    for (int i = 0; i < queens.size(); i++) {
        Queen q = queens[i];
        if (row == q.row || col == q.col ||
            row - col == q.row - q.col || row + col == q.row + q.col) {
            return false;
        }
    }
    return true;
}

bool Board::placeQueens(int col) {
    if (col >= 8) {
        return true;
    }

    for (int row = 0; row < 8; row++) {
        if (isSafe(row, col)) {
            placeQueen(row, col);
            if (placeQueens(col + 1)) {
                return true;
            }
            else {
                removeQueen();
            }
        }
    }

    return false;
}

void Board::display() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            bool isQueen = false;
            for (int i = 0; i < queens.size(); i++) {
                Queen q = queens[i];
                if (row == q.row && col == q.col) {
                    isQueen = true;
                    break;
                }
            }
            std::cout << (isQueen ? "Q " : "- ");
        }
        std::cout << std::endl;
    }
}
