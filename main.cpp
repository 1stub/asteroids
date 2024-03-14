#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "projectile.h"
#include "asteroid.h"
#include "collisions.h"
#include "score.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "asteroids", sf::Style::Close); 
    sf::Clock clock;
    sf::Time elapsed;
    int spawn = 200; //decremnts itself to increase difficulty
    int counter;
    float framerateLimit = 30.f;
    window.setFramerateLimit(framerateLimit);

    Ship ship;
    Projectile projectile;
    Collisions collide;
    Score score;
    
    collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroid
    collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids

    std::cout << collide.getArraySize() << std::endl;

    while (window.isOpen())
    {
        elapsed = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        collide.update(window, ship, projectile, score);
        if (elapsed.asMilliseconds() % spawn == 0) {
            collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids
            spawn--;
        }
        ship.update();
        projectile.update(window, ship);
        ship.drawShape(window);
        score.printScore(window);
        window.display();
    }

    return 0;
}
