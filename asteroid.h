#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ship.h"
#include "projectile.h"

class Asteroid{
    public:
        Asteroid();
        void updateAsteroid(sf::RenderWindow &window, Ship &ship, Projectile &bullet);
        void drawAsteroid(sf::RenderWindow &window);
    private:
        sf::CircleShape largeAsteroid;
        sf::CircleShape mediumAsteroid;
        sf::CircleShape smallAsteroid;
};

#endif
