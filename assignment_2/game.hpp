#ifndef GAME
#define GAME

#include <string>
#include <SFML/Graphics.hpp>

class Game
{
private:
  sf::RenderWindow m_window;
  bool paused, running;

  void sMovement();
  void sUserInput();
  void sRender();
  void sEnemySpawner();
  void sCollision();

public:
  Game(const std::string &configFile);
  void run();
};

#endif