#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "ship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "snake", sf::Style::Close);
    float framerateLimit = 60.f;
    window.setFramerateLimit(framerateLimit);

    Ship ship;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ship.drawShape(window);
        window.display();
    }

    return 0;
}
