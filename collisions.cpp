#include "collisions.h"

void Collisions::update(sf::RenderWindow &window, Ship &ship, Projectile &bullet, Asteroid &asteroid){
    for(auto& asteroid : asteroidVec){
        asteroid.updateAsteroid(window, ship, bullet);
    }
}
