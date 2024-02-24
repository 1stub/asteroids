#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle, int hit){
    asteroid.setPointCount(8); // 8 points to create an octagon
    asteroid.setFillColor(sf::Color::Black); 
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1.f);
    asteroid.setRadius(size);
    this->hitCount = hit;
    this->radius = size;
    this->angle = angle * 0.01745329;

    asteroid.setPosition(position);
}

void Asteroid::updateAsteroid(){
    sf::Vector2f position = asteroid.getPosition();

    if (position.x < 0)
        position.x = 800;
    else if (position.x > 800)
        position.x = 0.0f;

    if (position.y < 0)
        position.y = 800;
    else if (position.y > 800)
        position.y = 0.0f;
    asteroid.setPosition(position);
}

void Asteroid::drawAsteroid(sf::RenderWindow &window){
    window.draw(asteroid);
}

// used this https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
bool Asteroid::checkPoint(sf::FloatRect rect) {
    sf::Vector2f circleDistance;
    circleDistance.x = fabs((asteroid.getPosition().x + radius) - rect.getPosition().x);
    circleDistance.y = fabs((asteroid.getPosition().y + radius) - rect.getPosition().y);

    if (circleDistance.x > (rect.width/2 + radius)) { return false; }
    if (circleDistance.y > (rect.height/2 + radius)) { return false; }

    if (circleDistance.x <= (rect.width/2)) { return true; } 
    if (circleDistance.y <= (rect.height/2)) { return true; }

    float cornerDistance_sq = ((circleDistance.x - rect.width/2) * (circleDistance.x - rect.width/2)) + ((circleDistance.y - rect.height/2) * (circleDistance.y - rect.height/2));

    return (cornerDistance_sq <= (radius * radius));
}

void Asteroid::increaseHitCount(){
    hitCount++;
}

sf::Vector2f Asteroid::getVelocity(){
    return vel;
}

int Asteroid::getHitCount(){
    return hitCount;
}

sf::Vector2f Asteroid::getDiePosition(){
    return asteroid.getPosition();
}

void Asteroid::moveAsteroid(){
    asteroid.move(sf::Vector2f(vel.x*cos(angle), vel.y*sin(angle)));
}

sf::CircleShape Asteroid::getShape(){
    return asteroid;
}


