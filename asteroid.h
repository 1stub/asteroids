#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Asteroid{
    public:
        Asteroid();
        void updateAsteroid(sf::RenderWindow &window);
        void drawAsteroid(sf::RenderWindow &window);
    private:
        sf::CircleShape largeAsteroid;
        sf::CircleShape mediumAsteroid;
        sf::CircleShape smallAsteroid;
};

#endif
