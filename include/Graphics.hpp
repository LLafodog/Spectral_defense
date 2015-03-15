#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include<SFML/Graphics.hpp>

class Level;

class Graphics
{

public:
  Graphics(sf::RenderWindow* window);
  void draw(Level* lvl);
  virtual ~Graphics();

protected:
  void addLevel(Level* lvl, sf::VertexArray& va);

  sf::RenderWindow* m_window;
  sf::View m_view;
};

#endif // GRAPHICS_HPP
