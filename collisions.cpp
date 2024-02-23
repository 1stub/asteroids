#include "collisions.h"

void Collisions::update(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    for(auto& asteroid : asteroidVec){
        for (auto it = bullet.getProjectiles().begin(); it != bullet.getProjectiles().end(); ++it) {
        sf::FloatRect rect = it->shape.getGlobalBounds();
            if(asteroid.checkPoint(rect)){ //finds a point that is always on the line due to weird boinding box
                std::cout << "Collision detedted" << std::endl;
                asteroid.increaseHitCount();
                bullet.getProjectiles().erase(it);
                if (it == bullet.getProjectiles().end()) {
                    break; // Exit loop if iterator reaches the end
                }
            }
        }
        asteroid.drawAsteroid(window);
    }
}

void Collisions::createAsteroid(sf::Vector2f position, float size, float angle) {
    // Create a new asteroid and push it into the vector
    asteroidVec.emplace_back(position, size, angle);
}
