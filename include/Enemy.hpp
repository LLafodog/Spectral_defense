#ifndef ENEMY_HPP 
#define ENEMY_HPP 
 
#include<string>
using namespace std;

class Level;

class Enemy
{ 
public : 
  Enemy(string id, Level* lvl, double x, double y, double life = 100 , double speed = 1 );
  
  virtual void move();

  virtual ~Enemy(); 

protected: 
  double m_maxHealth;
  double m_health;
  string m_id;
  double m_speed;
  double m_x;
  double m_y;
  Level* m_level;
  
};

#endif // ENEMY_HPP
