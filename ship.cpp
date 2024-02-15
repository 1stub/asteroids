#include "ship.h"

Ship::Ship(){
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(0,10));
    shape.setPoint(1, sf::Vector2f(-5,0));
    shape.setPoint(2, sf::Vector2f(5,0));

    shape.setPosition(sf::Vector2f(20,20));
}

void Ship::drawShape(sf::RenderWindow &window){
    window.draw(shape);
}
