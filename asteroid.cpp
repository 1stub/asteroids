#include "asteroid.h"

Asteroid::Asteroid(){
    //Intended to set sizes for each asteroid;
    largeAsteroid.setPointCount(8);
    mediumAsteroid.setPointCount(8);
    smallAsteroid.setPointCount(8);

    largeAsteroid.setRadius(40);
    largeAsteroid.setFillColor(sf::Color::Black);
    largeAsteroid.setOutlineColor(sf::Color::White);
    largeAsteroid.setPosition(sf::Vector2f(200,200));
}

void Asteroid::updateAsteroid(sf::RenderWindow &window){
   drawAsteroid(window); 
}

void Asteroid::drawAsteroid(sf::RenderWindow &window){
    window.draw(largeAsteroid);
}
