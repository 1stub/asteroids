#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle, int hit){
    asteroid.setPointCount(8); // 8 points to create an octagon
    asteroid.setFillColor(sf::Color::Black); 
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1.f);
    this->hitCount = hit;
    this->radius = size;
    this->angle = angle * 0.01745329;
    const float angleIncrement = 3.14159f / 4.0f; // Angle increment for each point (45 degrees)

    float angleRad = 0.0f; // Initial angle

    for (int i = 0; i < 8; ++i) {
        float x = size * std::cos(angleRad); // X-coordinate of the point
        float y = size * std::sin(angleRad); // Y-coordinate of the point

        std::cout << x << " " << y << std::endl;
        asteroid.setPoint(i, sf::Vector2f(x, y)); // Set the point

        angleRad += angleIncrement; // Increment angle for the next point
    }
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

const sf::ConvexShape& Asteroid::getShape(){
    return asteroid;
}


