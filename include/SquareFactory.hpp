#ifndef SQUARE_FACTORY_HPP
#define SQUARE_FACTORY_HPP

#include<map>
#include<string>
using namespace std;

class Square;

class SquareFactory
// Singleton
{
public :
  
  Square* get(string id);
  Square* get(short id);
  static SquareFactory* getInstance();
  static void free() {delete m_self;}
  virtual ~SquareFactory();

protected:
  SquareFactory();
  void init();
  static SquareFactory* m_self;
  map<string,Square*>m_squares;

};

#endif // SQUARE_FACTORY_HPP
