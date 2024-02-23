#include "projectile.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Projectile::Projectile() : hasShot(false){ 
}

void Projectile::drawProjectile(sf::RenderWindow &window){
    for(const auto &bullet : bulletVector){
        window.draw(bullet.shape);
    }
}

void Projectile::shoot(Ship &ship){
    if(!hasShot){
        bullet newBullet;
        newBullet.angle = ship.getAngle();
        newBullet.velocity = sf::Vector2f(cos(newBullet.angle) * 3, sin(newBullet.angle) * 3);        
        // Create a thin rectangle as the projectile shape
        float thickness = 1.0f;
        float length = 15.0f;
        newBullet.shape.setSize(sf::Vector2f(length, thickness)); // Set the size of the rectangle
        newBullet.shape.setFillColor(sf::Color::White);

        // Position the rectangle at the tip of the ship
        sf::Vector2f shipPosition = ship.getPosition();
        sf::Vector2f offset = sf::Vector2f(cos(newBullet.angle) * length / 2, sin(newBullet.angle) * length / 2);
        newBullet.shape.setPosition(shipPosition + offset);

        newBullet.shape.setRotation(newBullet.angle * 180 / M_PI);
        bulletVector.push_back(newBullet);
    }
}

void Projectile::checkBounds(){
    for(size_t i = 0; i < bulletVector.size(); i++){
        if(bulletVector[i].shape.getPosition().x < 0 || bulletVector[i].shape.getPosition().x > 800 || bulletVector[i].shape.getPosition().y < 0
        || bulletVector[i].shape.getPosition().y > 800){
            bulletVector.erase(bulletVector.begin()+i);
            std::cout << "bullet erased array size: " << bulletVector.size() << std::endl;
        }
    }
}

void Projectile::update(sf::RenderWindow &window, Ship &ship){
    checkBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        shoot(ship);
        hasShot = true;
    } else {
        hasShot = false; // Reset the flag if the space key is released
    }
    for(auto& bullet : bulletVector){
        bullet.shape.move(sf::Vector2f(bullet.velocity.x *4, bullet.velocity.y *4));
    }
    drawProjectile(window);
}

std::vector<Projectile::bullet>& Projectile::getProjectiles(){
    return bulletVector;
}
    
