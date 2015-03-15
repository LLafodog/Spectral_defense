#ifndef CORE_HPP
#define CORE_HPP

#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<vector>

using namespace std;

const int WINDOW_WIDTH=800;
const int WINDOW_HEIGHT=600;

class Graphics;
class Game;
class Menu;
class Scene;

enum SCENE_ORDER
  {
    MENU,
    GAME,
    // NEW SCENE BEFORE
    EDITION,
    NB_SCENE
  };


class Core
{

public:
  Core();
  void run(); // game loop
  void quit() {m_window->close();}
  void putScene(size_t index);
  void restoreScene();
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
