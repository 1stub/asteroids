#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "projectile.h"
#include "asteroid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "asteroids", sf::Style::Close);
    float framerateLimit = 30.f;
    window.setFramerateLimit(framerateLimit);

    Ship ship;
    Projectile projectile;
    Asteroid asteroid;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ship.update();
        projectile.update(window, ship);
        ship.drawShape(window);
        asteroid.updateAsteroid(window, ship, projectile);
        window.display();
    }

    return 0;
}
