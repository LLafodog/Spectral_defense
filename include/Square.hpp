#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<string>
using namespace std;

class Tower;

class Square
{
public:
  Square(string id);
  inline string const getID() {return m_id;}
  inline void setPath(bool b) {m_path = false;} // YAGNI ?
  void update();
  virtual ~Square();

protected:
  string m_id;
  bool m_path;
  Tower* m_tower;
  
};

#endif // SQUARE_HPP
