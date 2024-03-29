#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "asteroid.h"
#include "ship.h"
#include "projectile.h"
#include "score.h"

//This serves the purpose for allowing me to create multiple asteroid objects at once.
class Collisions{
    public:
        void update(sf::RenderWindow &window,Ship &ship, Projectile &bullet, Score &score);
        void createAsteroid(sf::Vector2f position, float size, float angle, int hit);
        int getArraySize();
        void resetAsteroids();
    private:
        std::vector<Asteroid> asteroidVec;
        int lives = 3;
};

#endif
