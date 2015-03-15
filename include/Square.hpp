#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<string>
using namespace std;

class Square
{
public:
  Square(string id);
  inline string const getID() {return m_id;}
  virtual ~Square();

protected:
  string m_id;
  
};

#endif // SQUARE_HPP
