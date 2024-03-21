#ifndef MENU_H
#define MENU_H

#define MAX_ITEMS 2

#include <SFML/Graphics.hpp>
#include <iostream>

//Most of this comes from my pong clone
class Menu{
  public:
    Menu();
    ~Menu();
    void drawMenu(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    bool isPlay();
    void playPressed();
    int getSelectedItem(){return selectedItemIndex;};

  private:
    sf::Text menu[MAX_ITEMS];
    sf::Text title;
    sf::Font font;
    float width = 800;
    float height = 800;
    int selectedItemIndex;
    bool play = false;
};

#endif
