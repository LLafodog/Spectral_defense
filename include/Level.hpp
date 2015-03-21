#ifndef LEVEL_HPP
#define LEVEL_HPP

#include<vector>
#include<string>
using namespace std;

class Square;

class Level
{
public :
  Level(string path);
  Level(int w, int h);
  
  inline vector<vector<Square*>> getSquares() const {return m_squares;}
  inline short getWidth() {return m_squares[0].size();}
  inline short getHeight() {return m_squares.size();}
  void modifyTile(int x, int y, Square* s);
  virtual ~Level();

protected:
  vector<vector<Square*>> m_squares;
  

};

#endif // LEVEL_HPP
