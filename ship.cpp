#include "ship.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Ship::Ship(){
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    shape.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    shape.setPoint(2, sf::Vector2f(-10.0f, -7.5f));
 
    shape.setPosition(sf::Vector2f(WIDTH/2, HEIGHT/2));
}

void Ship::drawShape(sf::RenderWindow &window){
    window.draw(shape);
}

void Ship::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        angle += (5 * DEG2RAD);
        shape.rotate(5.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        angle -= (5 * DEG2RAD);
        shape.rotate(-5.f);
    }
    // Update velocity based on the ship's orientation if acceleration keys are pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (a < maxAcceleration) {
            a += accelerationRate;
        }
        applyForces();
        moveVel = v;
    }else{
        if(a>0){
            a-=accelerationRate;
        }
    }
    shape.move(moveVel);
}

void Ship::applyForces(){
       // Calculate force using F = ma
    sf::Vector2f f(m * a * cos(angle), m * a * sin(angle));

    // acceleration: change in velocity due to force f on object with mass m
    sf::Vector2f dv = f / m;

    // new velocity if acceleration dv applied
    sf::Vector2f new_v = v + dv;

    // only apply Lorentz factor if acceleration increases speed
    if (std::hypot(new_v.x, new_v.y) > std::hypot(v.x, v.y)) {
        // maximum speed objects may reach (the "speed of light")
        const float c = 4;

        float b = 1 - (std::hypot(v.x, v.y) * std::hypot(v.x, v.y)) / (c * c);
        if (b <= 0) b = 0;

        float lorentz_factor = 1 / std::sqrt(b);
        dv /= lorentz_factor;
    }

    // apply acceleration to object's velocity
    v += dv;

    // Update:
    // Allow acceleration in the forward direction to change the direction
    // of v by using the direction of new_v (without the Lorentz factor)
    // with the magnitude of v (that applies the Lorentz factor).
    if (std::hypot(v.x, v.y) > 0) {
        v = new_v / std::hypot(new_v.x, new_v.y) * std::hypot(v.x, v.y);
    }
    std::cout << v.x << ", " << v.y << std::endl;
}
