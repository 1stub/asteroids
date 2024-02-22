#include "collisions.h"

void Collisions::update(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    for(auto& asteroid : asteroidVec){
        asteroid.updateAsteroid(window, ship, bullet);
    }
}

void Collisions::createAsteroid(sf::Vector2f position, float size, float angle) {
    // Create a new asteroid and push it into the vector
    asteroidVec.emplace_back(position, size, angle);
}
