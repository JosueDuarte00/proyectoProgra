#pragma once
#include <SFML/Graphics.hpp>

class gem{

public:
    Gem(int type, float x, float y);
    int getType();
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    sf::FloatRect getBounds();    

private:
    int type;
    sf::Sprite sprite;
    static sf::Texture textures[5];
    static bool texturesLoaded;
    
};

