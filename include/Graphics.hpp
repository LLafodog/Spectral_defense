#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include<SFML/Graphics.hpp>
#include<assert.h>

class Game;
class Camera;
class Level;
class Square;

class Graphics
{

public:
  Graphics(sf::RenderWindow* window);
  void drawGame(Game* game);
  void drawLevel(Level* lvl, bool editoringMode = false);
  void drawTile(int x, int y, Square* s, int size);
  inline Camera* getCamera() {return m_camera;}
  inline void const display() {assert(m_window); m_window->display();}
  inline sf::RenderWindow* const getWindow() {return m_window;}

  virtual ~Graphics();

protected:
  void addLevel(Level* lvl, bool editoringMode = false);

  sf::RenderWindow* m_window;
  Camera* m_camera;
  
  sf::VertexArray m_currentArray;
  Level* m_currentLevel;

};

#endif // GRAPHICS_HPP
