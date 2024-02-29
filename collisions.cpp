#include "collisions.h"

void Collisions::update(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    // indicies of projectile/asteroid we want to remove after iteration
    int projectilesToRemove = -1;
    int asteroidsToRemove = -1;
    
    // Check collisions
    for(int i = 0; i < asteroidVec.size(); ++i){
        for (int j = 0; j < bullet.getProjectiles().size(); ++j) {
            sf::FloatRect rect = bullet.getProjectiles()[j].shape.getGlobalBounds();
            if(ship.sat_test_bullet(asteroidVec[i].getShape(), rect)){
                std::cout << "Collision detected" << std::endl;
                asteroidVec[i].increaseHitCount();
                if(asteroidVec[i].getHitCount() == 1){
                    for(int k = 0; k < 2; k++){
                        createAsteroid(asteroidVec[i].getDiePosition(), 15, rand() % 360, 1);
                    }
                }
                if (asteroidVec[i].getHitCount() == 2){
                    for(int k = 0; k < 2; k++){
                        createAsteroid(asteroidVec[i].getDiePosition(), 10, rand() % 360, 2);
                    }
                }
                projectilesToRemove = j; // Mark projectile index for removal
                asteroidsToRemove = i; // Mark asteroid index for removal
            }
        }
    } 
    if(projectilesToRemove >= 0 && asteroidsToRemove >= 0){
        asteroidVec.erase(asteroidVec.begin() + asteroidsToRemove);
        bullet.getProjectiles().erase(bullet.getProjectiles().begin() + projectilesToRemove);
    }
    for(auto &asteroid : asteroidVec){
        ship.loadLives(window, lives);
        if(ship.ShapeOverlap_SAT(ship.getShape(), asteroid.getShape())){ //this collision works with a rectangle bounding box around the circle so its not functioning well.
            std::cout << "collision with ship and asteroid detected" << std::endl;
            lives--;
            ship.shipReset(window);
            resetAsteroids();
        }
        asteroid.updateAsteroid();
        asteroid.moveAsteroid();
        asteroid.drawAsteroid(window);
    }
}

void Collisions::createAsteroid(sf::Vector2f position, float size, float angle, int hit) {
    // Create a new asteroid and push it into the vector
    asteroidVec.emplace_back(position, size, angle, hit);
}

int Collisions::getArraySize(){
    return asteroidVec.size();
}

void Collisions::resetAsteroids(){
    asteroidVec.clear();
    
    createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids
    createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids
    createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids
}
