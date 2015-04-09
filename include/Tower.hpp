#ifndef TOWER_HPP
#define TOWER_HPP

#include<string>

class Square;

class Tower
{
public:
  Tower(Square * s, std::string id);
  virtual void update() = 0;
  virtual ~Tower();

protected:
  virtual void updateTarget() = 0;
 
  std::string m_id;
  Square* m_square;
};

#endif // TOWER_HPP
