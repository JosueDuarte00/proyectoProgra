#pragma once
#include "gem.h"
#include <array>

class Board {

public:
    Board();
    void draw(sf::RenderWindow& window);
    bool swapGems(int x1, int y1, int x2, int y2);
    void detectMatches();
    void applyGravity();
    void fillBoard();
    int scorePoints();
    bool canSwap(int x1, int y1, int x2, int y2);
    bool isGameOver();
    void reset();

private:
        std::array<std::array<Gem*, 8>, 8> grid;
        int score;
        int moves;
};

