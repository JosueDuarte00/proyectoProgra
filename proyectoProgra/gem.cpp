#include "gem.h"
#include <iostream>

bool Gem::texturesLoaded = false;
sf::Texture Gem::textures[5];

Gem::Gem(int type, float x, float y) : type(type) {
    if (!texturesLoaded) {
        for (int i = 0; i < 5; ++i) {
            std::string filename = "assets/images/gem" + std::to_string(i + 1) + ".png";
            if (!textures[i].loadFromFile(filename)) {
                std::cerr << "Error loadign image: " << filename << std::endl;
            }
        }
        texturesLoaded = true;
    }

    sprite.setTexture(textures[type]);
    sprite.setPosition(x, y);
}




void Gem::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

int Gem::getType() {
    return type;
}

sf::FloatRect Gem::getBounds() {
    return sprite.getGlobalBounds();
}

void Gem::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
