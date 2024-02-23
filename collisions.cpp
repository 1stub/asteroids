#include "collisions.h"

void Collisions::update(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    // Create vectors to store indices of projectiles and asteroids to remove
    std::vector<int> projectilesToRemove;
    std::vector<int> asteroidsToRemove;
    
    // Check collisions
    for(int i = 0; i < asteroidVec.size(); ++i){
        for (int j = 0; j < bullet.getProjectiles().size(); ++j) {
            sf::FloatRect rect = bullet.getProjectiles()[j].shape.getGlobalBounds();
            if(asteroidVec[i].checkPoint(rect)){
                std::cout << "Collision detected" << std::endl;
                asteroidVec[i].increaseHitCount();
                projectilesToRemove.push_back(j); // Mark projectile index for removal
                if(asteroidVec[i].getHitCount() == 1){
                    for(int k = 0; k < 2; k++){
                        createAsteroid(asteroidVec[i].getDiePosition(), 15, rand() % 360, 1);
                    }
                }
                else if (asteroidVec[i].getHitCount() == 2){
                    for(int k = 0; k < 2; k++){
                        createAsteroid(asteroidVec[i].getDiePosition(), 10, rand() % 360, 2);
                    }
                }
                asteroidsToRemove.push_back(i); // Mark asteroid index for removal
            }
        }
    }
    
    for(int i = projectilesToRemove.size() - 1; i >= 0; --i) {
        bullet.getProjectiles().erase(bullet.getProjectiles().begin() + projectilesToRemove[i]);
    }
    
    for(int i = asteroidsToRemove.size() - 1; i >= 0; --i) {
        asteroidVec.erase(asteroidVec.begin() + asteroidsToRemove[i]);
    }
    
    for(auto &asteroid : asteroidVec){
        asteroid.updateAsteroid();
        asteroid.moveAsteroid();
        asteroid.drawAsteroid(window);
    }
}

void Collisions::createAsteroid(sf::Vector2f position, float size, float angle, int hit) {
    // Create a new asteroid and push it into the vector
    asteroidVec.emplace_back(position, size, angle, hit);
}
