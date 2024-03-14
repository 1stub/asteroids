#ifndef SCORE_H
#define SCORE_H

#include "SFML/Graphics.hpp"
#include <sstream>

class Score{
    public:
        Score();
        void increaseScore(int amount);
        void printScore(sf::RenderWindow &window);
    private:
        int scoreInt;
        int xPos;
        bool xPosChanged;
        sf::Font font;
        sf::Text score;
};

#endif
