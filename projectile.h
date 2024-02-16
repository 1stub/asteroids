#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "ship.h"

class Projectile{
    public:
        Projectile();
        void drawProjectile(sf::RenderWindow &window);
        void shoot(Ship &ship);
    private:
        float angle;
        sf::Vector2f v;
        sf::RectangleShape bullet;
};

#endif 
