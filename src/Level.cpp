#include<Level.hpp>
#include<Square.hpp>

#include<Parser.hpp>
#include<assert.h>

Level::Level(string path)
{
  m_squares.clear();
  m_squares=Parser::getInstance()->getLevel(path);
}

Level::Level(int w, int h)
{
  m_squares.clear();
  vector<Square*> line; line.clear();
  for(size_t i(0);i<w;i++)
    {
      for(size_t j(0);j<w;j++)
	{
	  line.push_back(new Square("grass"));
	}
      m_squares.push_back(line);
    }
}

void Level::modifyTile(int x, int y, Square* s)
{
  assert(s);
  if(x>=0 && y>=0 && y<m_squares.size() && x<m_squares[y].size())
    {
      m_squares[y][x]=s;
    }
}

Level::~Level()
{

}
