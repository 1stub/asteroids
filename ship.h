#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Ship{
    public:
        Ship();
        void drawShape(sf::RenderWindow &window);
        void setPosition(const sf::Vector2f& position);
        void update();
        void applyForces();
        sf::Vector2f getVelocity();
        float getAngle();
        sf::Vector2f getPosition();
    private:
        sf::ConvexShape shape;
        float angle = 0; //do cos and sin then multiply by velocity vector to account for rotations
        static constexpr float HEIGHT = 800;
        static constexpr float WIDTH = 800;
        static constexpr float DEG2RAD = 3.14159f / 180.0f;
        float m = 1; //mass of ship
        float a = 0;
        float accelerationRate = 0.0025;
        float maxAcceleration = 0.5;
        sf::Vector2f v;
        sf::Vector2f moveVel;
};

#endif
