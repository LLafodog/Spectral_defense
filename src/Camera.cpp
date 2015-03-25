#include<Camera.hpp>

#include<Level.hpp>
#include<TextureEngine.hpp>
using namespace sf;

Camera::Camera(RenderWindow* window) :
  m_window(window)
{
  assert(m_window);
  int width = window->getSize().x,
    height = window->getSize().y;
    m_view = View(Vector2f(width/2,height/2),Vector2f(width,height));
}

void Camera::update()
{
  move();
  m_window->setView(m_view);
}

void Camera::setLevel(Level* lvl)
{
  assert(lvl);
  if(lvl != m_level)
    { 
      m_level = lvl;
      int width = m_level->getWidth()*TILE_SIZE,
	height = m_level->getHeight()*TILE_SIZE;
      m_view = View(Vector2f(width/2,height/2),Vector2f(width,height));
      update();
    }

}

void Camera::move()
{
  double speed = 1;
  bool down = Keyboard::isKeyPressed(Keyboard::Down);
  bool up = Keyboard::isKeyPressed(Keyboard::Up);
  bool left = Keyboard::isKeyPressed(Keyboard::Left);
  bool right = Keyboard::isKeyPressed(Keyboard::Right);
  m_view.move((float)(down-up)*speed,(float)(right-left)*speed);
}

Camera::~Camera()
{
  
}
