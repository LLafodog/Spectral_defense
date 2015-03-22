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
  inline bool hasChanged() {return m_hasChanged;}
  inline void setChanged(bool b) {m_hasChanged = b;}
  inline void setSquares(vector<vector<Square*>> sqr) {m_squares=sqr; m_hasChanged=true;}
  void modifyTile(int x, int y, Square* s);
  virtual ~Level();

protected:
  vector<vector<Square*>> m_squares;
  bool m_hasChanged;

};

#endif // LEVEL_HPP
