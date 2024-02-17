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
    int x,y;
    if(!hasShot){
        bullet newBullet;
        newBullet.angle = ship.getAngle();
        newBullet.velocity = sf::Vector2f(cos(newBullet.angle) * 3, sin(newBullet.angle) * 3);
        newBullet.shape.setSize(sf::Vector2f(5,5));
        newBullet.shape.setPosition(ship.getPosition());
    
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
        bullet.shape.move(sf::Vector2f(bullet.velocity.x *2, bullet.velocity.y *2));
    }
    drawProjectile(window);
}

