#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SFML/Graphics.hpp>
#include "asteroid.h"
#include "ship.h"
#include "projectile.h"

//This serves the purpose for allowing me to create multiple asteroid objects at once.
class Collisions{
    public:
        void update(sf::RenderWindow &window,Ship &ship, Projectile &bullet, Asteroid &asteroid);
    private:
        std::vector<Asteroid> asteroidVec;
};

#endif
