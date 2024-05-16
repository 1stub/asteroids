#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "projectile.h"
#include "menu.h"
#include "collisions.h"
#include "score.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "asteroids", sf::Style::Close);
    sf::Clock clock;
    sf::Time elapsed;
    int spawn = 200; //decremnts itself to increase difficulty
    int counter;
    float framerateLimit = 30.f;
    window.setFramerateLimit(framerateLimit);

    Ship ship;
    Projectile projectile;
    Collisions collide;
    Menu menu;
    Score score;
    
    collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroid
    collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids

    std::cout << collide.getArraySize() << std::endl;

    while (window.isOpen())
    {
        elapsed = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!menu.isPlay()){  
            window.clear();
            menu.drawMenu(window);
            window.display();

            switch (event.type) {
              case sf::Event::KeyReleased:
                switch (event.key.code) {
                  case sf::Keyboard::Up:
                      menu.MoveUp();
                      break;

                  case sf::Keyboard::Down:
                      menu.MoveDown();
                      break;

                  case sf::Keyboard::Enter: 
                      switch (menu.getSelectedItem()) {
                          case 0:
                              menu.playPressed();
                              break;
                          case 1:
                              window.close();
                              break;
                      }
                      break; 
              }
              break;
          }
        }
        if(menu.isPlay()){
          float deltaTime = clock.restart().asSeconds();
          window.clear();
          collide.update(window, ship, projectile, score);
          if (elapsed.asMilliseconds() % spawn == 0) {
              collide.createAsteroid(sf::Vector2f(rand() % 780 ,rand() % 800), 40, rand() % 360, 0); //creates large asteroids
              spawn--;
          }
          ship.update();
          ship.updateParticles(deltaTime);
          projectile.update(window, ship);
          ship.drawParticles(window);
          ship.drawShape(window);
          score.printScore(window);
          window.display();
        }
    }
    return 0;
}
