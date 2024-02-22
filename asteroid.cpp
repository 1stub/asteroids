#include "asteroid.h"
#include <SFML/Graphics/CircleShape.hpp>

Asteroid::Asteroid(sf::Vector2f position, float size, float angle) : hitCount(0){
    asteroid.setPointCount(8); // 8 points to create an octagon
    asteroid.setFillColor(sf::Color::Black); 
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1.f);

    const float angleIncrement = 3.14159f / 4.0f; // Angle increment for each point (45 degrees)

    float angleRad = 0.0f; // Initial angle

    for (int i = 0; i < 8; ++i) {
        float x = size * std::cos(angleRad); // X-coordinate of the point
        float y = size * std::sin(angleRad); // Y-coordinate of the point
            
        std::cout << x << " " << y << std::endl;
        asteroid.setPoint(i, sf::Vector2f(x, y)); // Set the point

        angleRad += angleIncrement; // Increment angle for the next point
    }
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
        if(asteroid.getGlobalBounds().contains(it->shape.getPosition() + (0.5f * it->shape.getSize()))){
            std::cout << "Collision detedted" << std::endl;
            hitCount++;
            bullet.getProjectiles().erase(it);
            if (it == bullet.getProjectiles().end()) {
                break; // Exit loop if iterator reaches the end
            }
        }
    }
    drawBoundingBox(window,asteroid);
    drawAsteroid(window, asteroid); 
}

void Asteroid::drawAsteroid(sf::RenderWindow &window, sf::ConvexShape &asteroid){
    window.draw(asteroid);
}

