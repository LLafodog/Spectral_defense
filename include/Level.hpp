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
  
  void free();
  void modifyTile(int x, int y, Square* s);
  void update();
  

  // GETTER & SETTER
  inline vector<Square*> getSquares() const {return m_squares;}
  inline short getWidth() {return m_width;}
  inline short getHeight() {return m_height;}
  inline bool hasChanged() {return m_hasChanged;}
  inline void setChanged(bool b) {m_hasChanged = b;}
  inline void setSquares(vector<Square*> sqr) {m_squares=sqr; m_hasChanged=true;}
  

  virtual ~Level();

protected:
  int m_width;
  int m_height;
  vector<Square*> m_squares;
  bool m_hasChanged;

};

#endif // LEVEL_HPP
