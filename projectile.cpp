#include "projectile.h"
#include <SFML/Window/Keyboard.hpp>

Projectile::Projectile(){ 
}

void Projectile::drawProjectile(sf::RenderWindow &window){
    for(const auto &bullet : bulletVector){
        window.draw(bullet.shape);
    }
}

void Projectile::shoot(Ship &ship){
    //nothing now, working out how i want to structure this
    bullet newBullet;
    newBullet.angle = ship.getAngle();
    newBullet.velocity = ship.getVelocity();
    newBullet.shape.setSize(sf::Vector2f(5,5));
    newBullet.shape.setPosition(ship.getPosition());
    
    bulletVector.push_back(newBullet);
}

void Projectile::update(sf::RenderWindow &window, Ship &ship){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        shoot(ship);
    }
    for(auto& bullet : bulletVector){
        bullet.shape.move(sf::Vector2f(bullet.velocity.x *2, bullet.velocity.y *2));
    }
    drawProjectile(window);
}

