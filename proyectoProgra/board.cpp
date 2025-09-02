#include "board.h"
#include <cstdlib>
#include <ctime>

Board::Board() : score(0), moves(20) {
    std::srand(static_cast<unsigned>(std::time(0)));
    fillBoard();
}

void Board::draw(sf::RenderWindow& window) {
    for (auto& row : grid) {
        for (auto& gem : row) {
            if (gem)
                gem->draw(window);
        }
    }
}

bool Board::swapGems(int x1, int y1, int x2, int y2) {
    if (!canSwap(x1, y1, x2, y2)) return false;
    std::swap(grid[y1][x1], grid[y2][x2]);
    detectMatches();
    return true;
}

void Board::detectMatches() {
}

void Board::applyGravity() {
}

void Board::fillBoard() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            int type = std::rand() % 5;
            grid[y][x] = new gem(type, x * 64, y * 64);
        }
    }
}

int Board::scorePoints() {
    return score;
}

bool Board::canSwap(int x1, int y1, int x2, int y2) {
    return true;
}

bool Board::isGameOver() {
    return moves <= 0;
}

void Board::reset() {
    score = 0;
    moves = 20;
    fillBoard();
}