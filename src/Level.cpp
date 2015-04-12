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
  Parser::getInstance()->createLevelFrom(path,&m_squares,&m_width,&m_height);
  m_hasChanged = true;
}

Level::Level(int w, int h) : 
  m_width(w),
  m_height(h)
{
  m_squares.clear();
  for(size_t i(0);i<h;i++)
    {
      for(size_t j(0);j<w;j++)
	{
	  m_squares.push_back(SquareFactory::getInstance()->get("grass",i*TILE_SIZE,j*TILE_SIZE));
	}
    }
}

void Level::modifyTile(int x, int y, Square* s)
{
  assert(s);

    for(int i(0);i<m_squares.size();i++)
    {
      Square* actualSquare = m_squares[i];
      assert(actualSquare);
      if(actualSquare->getX() == x-x%TILE_SIZE && actualSquare->getY() == y-y%TILE_SIZE)
	{
	  delete actualSquare;
	  m_hasChanged = true;
	  m_squares[i] = s;
	}
    }
}

void Level::update()
{
  for(Square* s: m_squares)
    {
      assert(s);
      s->update();
    }

}

void Level::free()
{
  for(Square* s : m_squares){assert(s);delete s;}
}



Level::~Level()
{
   
}
