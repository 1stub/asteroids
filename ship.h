#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Ship{
    public:
        struct Particle {
            sf::CircleShape shape;
            sf::Vector2f velocity;
            float lifetime;
        };
        Ship();
        void drawShape(sf::RenderWindow &window);
        const sf::ConvexShape& getShape();
        void setPosition(const sf::Vector2f& position);
        void createParticle(sf::Vector2f position, sf::Vector2f vel);
        void drawParticles(sf::RenderWindow& window);
        void updateParticles(float deltaTime);
        void update();
        void applyForces();
        sf::Vector2f getVelocity();
        float getAngle();
        sf::Vector2f getPosition();
        void loadLives(sf::RenderWindow &window, int lives);

        bool ShapeOverlap_SAT(const sf::ConvexShape& shape1, const sf::ConvexShape& shape2); 
        bool sat_test_bullet(const sf::ConvexShape &sp1, const sf::FloatRect &sp2, sf::Vector2f *out_mtv = nullptr);
        
        void shipReset(sf::RenderWindow &window);
    private:
        std::vector<Particle> particles;
        sf::Clock particleClock;
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
