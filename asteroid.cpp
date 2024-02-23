#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle) : hitCount(0){
    asteroid.setPointCount(8); // 8 points to create an octagon
    asteroid.setFillColor(sf::Color::Black); 
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1.f);
    asteroid.setRadius(size);
    this->radius = size;

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

