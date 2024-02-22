#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle) : hitCount(0){
    asteroid.setPointCount(8);
    asteroid.setRadius(size);
    asteroid.rotate(angle);
}

void Asteroid::updateAsteroid(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    for(auto bullet : bullet.getProjectiles()){
        if(bullet.shape.getGlobalBounds().intersects(asteroid.getGlobalBounds())){
            hitCount++;
        }
    } 
    drawAsteroid(window, asteroid); 
}

void Asteroid::drawAsteroid(sf::RenderWindow &window, sf::CircleShape asteroid){
    window.draw(asteroid);
}
