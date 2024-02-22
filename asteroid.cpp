#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle) : hitCount(0){
    asteroid.setPointCount(8); // 8 points to create an octagon
    asteroid.setFillColor(sf::Color::Black); 
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1.f);
    asteroid.setRadius(size);
    this->radius = size;

    asteroid.setPosition(position);
}

void drawBoundingBox(sf::RenderWindow& window, const sf::ConvexShape& shape) {
    // Get the global bounds of the shape
    sf::FloatRect bounds = shape.getGlobalBounds();

    // Create a rectangle shape to represent the bounding box
    sf::RectangleShape boundingBox(sf::Vector2f(bounds.width, bounds.height));
    boundingBox.setPosition(bounds.left, bounds.top);
    boundingBox.setFillColor(sf::Color::Transparent);
    boundingBox.setOutlineColor(sf::Color::Red); // Outline color
    boundingBox.setOutlineThickness(1.0f); // Outline thickness

    // Draw the bounding box
    window.draw(boundingBox);
}

void Asteroid::updateAsteroid(sf::RenderWindow &window, Ship &ship, Projectile &bullet){
    for (auto it = bullet.getProjectiles().begin(); it != bullet.getProjectiles().end(); ++it) {
        sf::FloatRect rect = it->shape.getGlobalBounds();
        if(checkPoint(rect)){ //finds a point that is always on the line due to weird boinding box
            std::cout << "Collision detedted" << std::endl;
            hitCount++;
            bullet.getProjectiles().erase(it);
            if (it == bullet.getProjectiles().end()) {
                break; // Exit loop if iterator reaches the end
            }
        }
    }
    drawAsteroid(window, asteroid); 
}

void Asteroid::drawAsteroid(sf::RenderWindow &window, sf::CircleShape &asteroid){
    window.draw(asteroid);
}

// used this https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
bool Asteroid::checkPoint(sf::FloatRect rect) {
    sf::Vector2f circleDistance;
    circleDistance.x = abs((int)asteroid.getPosition().x - (int)rect.getPosition().x);
    circleDistance.y = abs((int)asteroid.getPosition().y - (int)rect.getPosition().y);

    if (circleDistance.x > (rect.width/2 + radius)) { return false; }
    if (circleDistance.y > (rect.height/2 + radius)) { return false; }

    if (circleDistance.x <= (rect.width/2)) { return true; } 
    if (circleDistance.y <= (rect.height/2)) { return true; }

    float cornerDistance_sq = ((circleDistance.x - rect.width/2) * (circleDistance.x - rect.width/2)) + ((circleDistance.y - rect.height/2) * (circleDistance.y - rect.height/2));

    return (cornerDistance_sq <= (radius * radius));
}

