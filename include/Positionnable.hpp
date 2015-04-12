#ifndef POSITIONNABLE_H
#define POSITIONNABLE_H

#include<SFML/System/Vector2.hpp>
#include<Defines.hpp>

using namespace sf;

class Positionnable
{
public:
  Positionnable(float x=0, float y=0, float size = TILE_SIZE);

  virtual ~Positionnable();

  /// ============ GETTER =================
  virtual const float  getX() {return m_x;}
  virtual const float getY() {return m_y;}
  virtual Vector2f getPosition() {return Vector2f(m_x,m_y);}
  virtual const float getSize() {return m_size;}
  /// ============ SETTER =================
  virtual void setX(float x) {m_x=x;}
  virtual void setY(float y) {m_y=y;}
  virtual void setPosition(float x, float y) {m_x=x;m_y=y;}
  virtual void setPosition(Vector2f v){m_x=v.x;m_y=v.y;}
  virtual void setSize(float s) {m_size=s;}

protected:
  float m_x;
  float m_y;
  float m_size;
};

#endif // POSITIONNABLE_H
