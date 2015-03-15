#include<Level.hpp>
#include<Square.hpp>

#include<Parser.hpp>

Level::Level(string path)
{
  m_squares.clear();
  m_squares=Parser::getInstance()->getLevel(path);
}

Level::~Level()
{

}
