#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "ship.h"
#include "projectile.h"

class Asteroid{
    public:
        Asteroid(sf::Vector2f position, float size, float angle, int hit);
        void updateAsteroid();
        void drawAsteroid(sf::RenderWindow &window);
        bool checkPoint(sf::FloatRect rect);
        void increaseHitCount();
        sf::Vector2f getVelocity();
        int getHitCount();
        sf::Vector2f getDiePosition();
        void moveAsteroid();
        const sf::ConvexShape &getShape();
    private:
        sf::ConvexShape asteroid;
        sf::Vector2f vel = sf::Vector2f(2,2);
        float angle;
        float radius;
        int hitCount;
};

#endif
