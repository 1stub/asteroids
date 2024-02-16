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
        typedef struct{
            float angle;
            sf::Vector2f velocity;
            sf::RectangleShape shape; 
        } bullet;
    private:
        std::vector<bullet> bulletVector;
};

#endif 
