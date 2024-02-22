#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "ship.h"
#include "projectile.h"

class Asteroid{
    public:
        Asteroid(sf::Vector2f position, float size, float angle);
        void updateAsteroid(sf::RenderWindow &window, Ship &ship, Projectile &bullet);
        void drawAsteroid(sf::RenderWindow &window, sf::CircleShape asteroid); 
    private:
        sf::CircleShape asteroid;
        int hitCount;
};

#endif
