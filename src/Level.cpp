#include<Level.hpp>
#include<Square.hpp>

#include<Parser.hpp>
#include<SquareFactory.hpp>
#include<assert.h>

// debug
#include<iostream>
using namespace std;
//

Level::Level(string path)
{
  m_squares.clear();
  m_squares=Parser::getInstance()->getLevel(path); // to do passer le tableau en arg pour mémoire
  m_hasChanged = true;
}

Level::Level(int w, int h)
{
  m_squares.clear();
  vector<Square*> line; line.clear();
  for(size_t i(0);i<h;i++)
    {
      line.clear();
      for(size_t j(0);j<w;j++)
	{
	  line.push_back(SquareFactory::getInstance()->get("grass"));
	}
      m_squares.push_back(line);
    }
}

void Level::modifyTile(int x, int y, Square* s)
{
  assert(s);
  if(x>=0 && y>=0 && y<m_squares.size() && x<m_squares[y].size())
    {
      // fuite
      // delete m_squares[y][x];
      m_hasChanged = true;
      m_squares[y][x]=s;
    }
}

void Level::free()
{
  // leak memory :(
  for (vector<Square*> line : m_squares)
    {
      for(Square* s : line){assert(s);delete s;}
    }
}



Level::~Level()
{
   
}
