#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<string>
#include<Defines.hpp>
#include<Positionnable.hpp>
using namespace std;

class Tower;

class Square : public Positionnable
{
public:
  Square(string id, float x = 0, float y = 0, float size = TILE_SIZE);
  inline string const getID() {return m_id;}
  inline void setPath(bool b) {m_path = false;} // YAGNI ?
  virtual void update();
  virtual inline bool isGenerator() const {return false;}
  virtual inline Square* getCopy() {return new Square(*this);}
  virtual ~Square();

protected:
  string m_id;
  bool m_path;
  Tower* m_tower;
  
};

#endif // SQUARE_HPP
