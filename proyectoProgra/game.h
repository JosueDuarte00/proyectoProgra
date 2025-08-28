#pragma once
#include <SFML/Graphics.hpp>
#include "board.h"

class game {

public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void resetGame();

    sf::RenderWindow window;

    int gameState;

    Board board;

    sf::Texture backgroundTex;
    sf::Sprite background;

    sf::Texture playTex;
    sf::Sprite playButton;

    sf::Texture restartTex;
    sf::Sprite restartButton;

    sf::Texture exitTex;
    sf::Sprite exitButton;

};



