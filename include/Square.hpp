#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<string>
using namespace std;

class Square
{
public:
  Square(string id);
  inline string const getID() {return m_id;}
  inline void setPath(bool b) {m_path = false;} // YAGNI ?
  virtual ~Square();

protected:
  string m_id;
  bool path;
  
};

#endif // SQUARE_HPP
