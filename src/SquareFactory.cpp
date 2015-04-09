#include<SquareFactory.hpp>
#include<assert.h>
#include<Square.hpp>
#include<Defines.hpp>

// debug
#include<iostream>
using namespace std;

SquareFactory* SquareFactory::m_self=nullptr;

SquareFactory::SquareFactory()
{

  init();
}

void SquareFactory::init()
{

  for(size_t i(0);i<SQUARES_ID.size();i++)
    {
      Square * sq = new Square(SQUARES_ID[i]);
      switch(i)
	{
	default : sq->setPath(true); break;
	}
      m_squares.insert(pair<string,Square*>(SQUARES_ID[i],sq));
    }
  m_squares.insert(pair<string,Square*>("grass",new Square("grass")));

}

SquareFactory* SquareFactory::getInstance()
{
  if(m_self==nullptr)m_self=new SquareFactory();
  return m_self;
}

Square* SquareFactory::get(string id)
{
  if(m_self==nullptr){m_self=new SquareFactory();}
  assert(m_squares[id]);
  return new Square(*m_squares[id]);
}

Square* SquareFactory::get(short id)
{
  return get(SQUARES_ID[id]);
}

SquareFactory::~SquareFactory()
{
  for(auto pair: m_squares){delete pair.second;}
}
