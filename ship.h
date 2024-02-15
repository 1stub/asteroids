#include <SFML/Graphics.hpp>

class Ship{
    public:
       Ship();
       void drawShape(sf::RenderWindow &window);
    private:
        sf::ConvexShape shape;
};
