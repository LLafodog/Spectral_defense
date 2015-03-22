#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include<SFML/Graphics.hpp>
#include<assert.h>

class Game;
class Level;
class Square;

class Graphics
{

public:
  Graphics(sf::RenderWindow* window);
  void drawGame(Game* game);
  void drawLevel(Level* lvl);
  void drawTile(int x, int y, Square* s);
  inline void const display() {assert(m_window); m_window->display();}
  inline sf::RenderWindow* const getWindow() {return m_window;}
  inline void setView(sf::View view){m_view=view;}
  inline void setDefaultView(){setView(m_window->getDefaultView());m_window->setView(m_view);}
  virtual ~Graphics();

protected:
  void addLevel(Level* lvl);

  sf::RenderWindow* m_window;
  sf::View m_view;
  
  sf::VertexArray m_currentArray;
  Level* m_currentLevel;

};

#endif // GRAPHICS_HPP
