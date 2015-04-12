#include<SquareFactory.hpp>
#include<assert.h>

#include<EnemyGenerator.hpp>
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
      Square* sq = new Square(SQUARES_ID[i]) ;
      sq->setPath(true);
      assert(sq);
      m_squares.insert(pair<string,Square*>(SQUARES_ID[i],sq));
    }
  m_squares.insert(pair<string,Square*>("grass",new Square("grass")));

}

SquareFactory* SquareFactory::getInstance()
{
  if(m_self==nullptr)m_self=new SquareFactory();
  return m_self;
}

Square* SquareFactory::get(string id, int x, int y, bool generatoring)
{
  if(m_self==nullptr){m_self=new SquareFactory();}
  //  cout << id << endl;
  if(generatoring || id.find('*')!=string::npos)
    {
      string realID = "";
      for(char letter : id){if(letter!='*')realID+=letter;}
      assert(m_squares[realID]); 
      EnemyGenerator* eg = new EnemyGenerator(realID,x,y); 
      return eg;
    }
  else
    {
      assert(m_squares[id]); 
      Square* s = m_squares[id]->getCopy();
      s->setPosition(x,y);
      return s;
    }
}

Square* SquareFactory::get(short id, int x, int y, bool generatoring)
{
  return get(SQUARES_ID[id],x,y,generatoring);
}

SquareFactory::~SquareFactory()
{
  for(auto pair: m_squares){delete pair.second;}
}
