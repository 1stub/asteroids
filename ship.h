#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Ship{
    public:
       Ship();
       void drawShape(sf::RenderWindow &window);
       void update();
       void applyForces();
    private:
        sf::ConvexShape shape;
        static const int HEIGHT = 800;
        static const int WIDTH = 800;
        float m = 1; //mass of ship
        float a = 0;
        float accelerationRate = 0.01;
        float maxAcceleration = 1;
        sf::Vector2f v;
};
