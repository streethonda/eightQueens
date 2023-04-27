#include <iostream>
#include "queen_board.h"

int main() {
    Board board;
    board.placeQueens(0);
    board.display();
    return 0;
}
