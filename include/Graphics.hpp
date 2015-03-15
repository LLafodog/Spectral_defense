#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include<SFML/Graphics.hpp>

class Game;
class Level;

class Graphics
{

public:
  Graphics(sf::RenderWindow* window);
  void drawGame(Game* game);
  void drawLevel(Level* lvl);
  inline sf::RenderWindow* const getWindow() {return m_window;}
  virtual ~Graphics();

protected:
  void addLevel(Level* lvl, sf::VertexArray& va);

  sf::RenderWindow* m_window;
  sf::View m_view;
};

#endif // GRAPHICS_HPP
