#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>

Menu::Menu(){
	if (!font.loadFromFile("./fonts/Eight-Bit Madness.ttf"))
	{
		//Error handle
	}
	title.setFont(font);
	title.setStyle(sf::Text::Bold);
	title.setCharacterSize(128);
	title.setFillColor(sf::Color::White);
	title.setPosition(sf::Vector2f(width/4, height / 24));
	title.setString("Asteroids");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
  menu[0].setCharacterSize(64);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
  menu[1].setCharacterSize(64);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

Menu::~Menu(){
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(title);
  window.draw(menu[0]);
  window.draw(menu[1]);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::playPressed(){
  play = true;
}

bool Menu::isPlay(){
  return play;
}
