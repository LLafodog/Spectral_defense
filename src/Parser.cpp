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

vector<vector<Square*>> Parser::getLevel(string path)
{
  fstream reader(TO_LEVEL_FOLDER+path.c_str());
  assert(reader.is_open());
  string line;

  vector<vector<Square*>> res; res.clear();

  while(getline(reader,line))
    {
      vector<Square*> sq_line; sq_line.clear();
      string word="";
      for(char letter:line)
	{
	  if(letter!=' ')word+=letter;
	  else
	    {
	      sq_line.push_back(SquareFactory::getInstance()->get(word));
	      word="";
	    }
	}
      res.push_back(sq_line);
    }
  return res;
}

Parser::~Parser()
{

}
