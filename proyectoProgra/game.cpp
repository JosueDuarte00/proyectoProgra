#include "game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Mini CandyCrush Game"), gameState(0) {
    if (!backgroundTex.loadFromFile("assets/images/background.png")) {
        std::cout << "Error: unable to open background.png\n";
    }
    background.setTexture(backgroundTex);

    if (!playTex.loadFromFile("assets/images/play_button.png")) {
        std::cout << "Error: unable to open play_button.png\n";
    }
    playButton.setTexture(playTex);
    playButton.setPosition(300, 400);

    if (!restartTex.loadFromFile("assets/images/restart_button.png")) {
        std::cout << "Error: unable to open restart_button.png\n";
    }
    restartButton.setTexture(restartTex);
    restartButton.setPosition(250, 400);

    if (!exitTex.loadFromFile("assets/images/exit_button.png")) {
        std::cout << "Error: unable to open exit_button.png\n";
    }
    exitButton.setTexture(exitTex);
    exitButton.setPosition(450, 400);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (gameState == 0 && playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    gameState = 1;
                }
                else if (gameState == 2) {
                    if (restartButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        resetGame();
                        gameState = 1;
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        window.close();
                    }
                }
            }
        }
    }
}

void Game::update() {
    if (gameState == 1) {
        if (board.isGameOver()) {
            gameState = 2;
        }
    }
}

void Game::render() {
    window.clear();

    if (gameState == 0) { 
        window.draw(background);
        window.draw(playButton);
    }
    else if (gameState == 1) {
        board.draw(window);
    }
    else if (gameState == 2) {
        window.draw(background);
        window.draw(restartButton);
        window.draw(exitButton);
    }

    window.display();
}

void Game::resetGame() {
    board.reset();
    gameState = 1;
}
