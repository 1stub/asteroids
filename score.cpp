#include "score.h"

Score::Score(){
    if(!font.loadFromFile("/home/stub/repos/asteroids/fonts/Eight-Bit Madness.ttf")){ } //error
    score.setFont(font);
    score.setStyle(sf::Text::Bold);
    score.setCharacterSize(32);
    xPos = 750;
    xPosChanged = false;
    score.setPosition(sf::Vector2f(xPos,5));
    score.setString("0");
    scoreInt = 0;
}

void Score::increaseScore(int amount){
    std::stringstream ss;
    scoreInt+=amount;
    if(scoreInt >= 1000 && !xPosChanged){
        xPos -= 32;
        score.setPosition(sf::Vector2f(xPos, 5));
        xPosChanged = true;
    }
    ss << scoreInt;
    score.setString(ss.str());
}

void Score::printScore(sf::RenderWindow &window){
    window.draw(score); 
}
