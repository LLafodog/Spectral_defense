#ifndef CAMERA_HPP
#define CAMERA_HPP

#include<SFML/Graphics.hpp>
#include<assert.h>

class Level;

class Camera
{
public:
  Camera(sf::RenderWindow* window);
  inline void setView(sf::View view){m_view=view;}
  void setLevel(Level* lvl);
  inline void setDefaultView(){m_window->setView(m_window->getDefaultView());}
  void update();
  void move();
  virtual ~Camera();

protected :
  sf::RenderWindow* m_window;
  sf::View m_view;
  Level* m_level;

};

#endif // CAMERA_HPP
