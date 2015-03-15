#ifndef CORE_HPP
#define CORE_HPP

#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<vector>

using namespace std;

class Graphics;
class Game;
class Menu;
class Scene;

class Core
{

public:
  Core(sf::RenderWindow* w);
  void run(); // game loop
  void quit() {m_window->close();}
  void goToMenu();
  void quitMenu();
  virtual ~Core();

protected:
  void init();
  void update();
  void draw() ;

  Graphics* m_graphics;
  sf::RenderWindow* m_window;
  sf::Clock m_clock;
  Menu* m_menu;
  Game* m_game;
  vector<Scene*> m_scenes;
  Scene* m_currentScene;
  size_t m_currentSceneIndex;
};

#endif // CORE_HPP
