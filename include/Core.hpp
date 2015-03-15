#ifndef CORE_HPP
#define CORE_HPP

#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<vector>

using namespace std;

class Graphics;
class Level;
class Menu;

class Core
{

public:
  Core(sf::RenderWindow* w);
  void run(); // game loop
  virtual ~Core();

protected:
  void init();
  void addLevels();
  void gameControl(sf::Event event);
  void update();
  void draw() ;

  Graphics* m_graphics;
  sf::RenderWindow* m_window;
  vector<Level> m_levels;
  int m_currentLevel;
  sf::Clock m_clock;
  Menu* m_menu;
};

#endif // CORE_HPP
