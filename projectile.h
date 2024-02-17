#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "ship.h"

class Projectile{
    public:
        Projectile();
        void drawProjectile(sf::RenderWindow &window);
        void shoot(Ship &ship);
        void update(sf::RenderWindow &window, Ship &ship);
        void checkBounds();
        typedef struct{
            float angle;
            sf::Vector2f velocity;
            sf::ConvexShape shape; 
        } bullet;
    private:
        std::vector<bullet> bulletVector;
        bool hasShot;
};

#endif 
