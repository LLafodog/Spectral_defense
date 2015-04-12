#include<Parser.hpp>

#include<SquareFactory.hpp>
#include<Square.hpp>
#include<fstream>
#include<assert.h>

Parser* Parser::m_self = nullptr;

Parser::Parser()
{
  
}

Parser* Parser::getInstance()
{
  if(m_self==nullptr)
    {
      m_self=new Parser();
    }
  return m_self;
}

void Parser::createLevelFrom(string path,vector<Square*>* v, int* w, int* h)
{
  fstream reader(TO_LEVEL_FOLDER+path.c_str());
  assert(reader.is_open());
  string line;

  v->clear();
  int x = 0, y = 0;
  while(getline(reader,line))
    {
      string word="";
      x = 0;
      for(char letter:line)
	{
	  if(letter!=' ')word+=letter;
	  else
	    {
	      v->push_back(SquareFactory::getInstance()->get(word,x,y));
	      word="";
	      x+=TILE_SIZE;
	    }
	}
      y+=TILE_SIZE;
    }
  *h=y/TILE_SIZE;
  *w = x/TILE_SIZE;
}

Parser::~Parser()
{

}
