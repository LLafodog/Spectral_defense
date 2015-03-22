#include<Camera.hpp>

#include<Level.hpp>
#include<TextureEngine.hpp>
using namespace sf;

Camera::Camera(RenderWindow* window) :
  m_window(window)
{

  int width = window->getSize().x,
    height = window->getSize().y;
    m_view = View(Vector2f(width/2,height/2),Vector2f(width,height));
}

void Camera::update()
{
  assert(m_window);
  m_window->setView(m_view);
}

void Camera::setLevel(Level* lvl)
{
  assert(lvl);
  if(lvl!=m_level)
    {
      m_level = lvl;
      int width = m_level->getWidth()*TILE_SIZE,
	height = m_level->getHeight()*TILE_SIZE;
      m_view = View(Vector2f(width/2,height/2),Vector2f(width,height));
      update();
    }

}

Camera::~Camera()
{
  
}
