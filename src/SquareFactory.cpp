#include<SquareFactory.hpp>
#include<assert.h>
#include<Square.hpp>

SquareFactory* SquareFactory::m_self=nullptr;

SquareFactory::SquareFactory()
{

  init();
}

void SquareFactory::init()
{
  m_squares.insert(pair<string,Square*>("grass",new Square("grass")));
  m_squares.insert(pair<string,Square*>("ground",new Square("ground")));
}

SquareFactory* SquareFactory::getInstance()
{
  if(m_self==nullptr)m_self=new SquareFactory();
  return m_self;
}

Square* SquareFactory::get(string id)
{
  if(m_self==nullptr){m_self=new SquareFactory();}
  //  Square* copy =new Square(m_squares[id]);
  //  return copy;
  assert(m_squares[id]);
  return m_squares[id];
}

Square* SquareFactory::get(short id)
{
  switch(id)
    {
    case GRASS: return get("grass");break;
    case GROUND:return get("ground");break;
    default : assert(false); break;
    }
}

SquareFactory::~SquareFactory()
{
  //for(auto pair: m_squares){delete pair.second;}
}
