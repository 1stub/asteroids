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
        void drawAsteroid(sf::RenderWindow &window);
        bool checkPoint(sf::FloatRect rect);
        void increaseHitCount();
        sf::Vector2f getVelocity();
    private:
        sf::CircleShape asteroid;
        sf::Vector2f vel = sf::Vector2f(2,2);
        float radius;
        int hitCount;
};

#endif
