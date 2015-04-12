#include<Square.hpp>

#include<Tower.hpp>

Square::Square(string id, float x, float y, float size):
  Positionnable(x,y,size),
  m_id(id)
{
  m_path= false;
  m_tower = nullptr;
}

void Square::update()
{
  if(m_tower)
    {
      m_tower->update();
    }
}

Square::~Square()
{
  if(m_tower)delete m_tower;
}
