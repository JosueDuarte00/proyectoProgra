#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::VideoMode mode(200, 200);
    sf::RenderWindow window(mode, "SFML works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(0.f, 0.f);

    while (window.isOpen()) {
        sf::Event e; // Declarar el evento

        while (window.pollEvent(e)) { // Pasar el evento por referencia
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return 0;
}
