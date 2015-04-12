#include<Enemy.hpp>

#include<assert.h>
#include<Level.hpp>

Enemy::Enemy(string id, Level* lvl, double x, double y, double maxHealth, double speed ) :
  m_id(id),
  m_level(lvl),
  m_x(x),
  m_y(y),
  m_maxHealth(maxHealth),
  m_speed(speed)
{
  m_health = m_maxHealth ;
  m_level = nullptr;
}

void Enemy::move()
{
  assert(m_level);
  m_x+=m_speed;
  m_y+=m_speed;
}

Enemy::~Enemy()
{
  
}
