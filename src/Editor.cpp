#include<Editor.hpp>

#include<Core.hpp>
#include<Graphics.hpp>
#include<Level.hpp>
#include<TextureEngine.hpp>
#include<SquareFactory.hpp>
#include<Square.hpp>
#include<Defines.hpp>
#include<assert.h>
#include<fstream>

// debug
using namespace std;
#include<iostream>

using namespace sf;

Editor::Editor(Core* core) :
  Scene(core)
{
  m_currentSquare=0;
  m_level=new Level(15,15);
  m_mouse = Vector2f(-1,-1);
}
 
void Editor::updateControl(sf::Event event)
{
  switch(event.type)
    {
    case Event::KeyPressed:
      {
	switch(event.key.code)
	  {
	  default: break;
	  case Keyboard::PageDown: 
	    {
	      m_currentSquare--; 
	      if(m_currentSquare<0)
		{
		  m_currentSquare = SQUARES_ID.size() -1 ;
		}
	    } break;
	  case Keyboard::PageUp: {m_currentSquare++; m_currentSquare%=SQUARES_ID.size();} break;
	  }
      }break;
    default: break;
    }

  if(Mouse::isButtonPressed(Mouse::Left)) modifyTile(m_mouse.x/TILE_SIZE,m_mouse.y/TILE_SIZE); 
  // Combinaison	    
  if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::S) ){saveLevel();}
  if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::L) ){cout << "Load which level ? \n ";string path;cin>>path; loadLevel(path);}
}

void Editor::update(sf::Vector2f mouse)
{
  m_mouse = mouse ;
}

void Editor::draw(Graphics* g)
{
  assert(g);
  g->drawLevel(m_level);
  drawTileAtMouse(g);
  g->display();
}

void Editor::drawTileAtMouse(Graphics* g)
{
  assert(g);
  int xt=m_mouse.x;
  xt -= xt%TILE_SIZE;
  int yt=m_mouse.y;
  yt-=yt%TILE_SIZE;
  g->drawTile(xt,yt,SquareFactory::getInstance()->get(m_currentSquare));
}

void Editor::modifyTile(int x, int y)
{
  assert(m_level);
  m_level->modifyTile(x,y,SquareFactory::getInstance()->get(m_currentSquare));
}


void Editor::saveLevel()
{
  string line="",name="";
  cout << " Name of level : " << endl;
  cin >> name;
  ofstream writter(name.c_str());
  assert(m_level);
  auto squares =  m_level->getSquares();
  for(size_t i(0);i< squares.size(); i++)
    {
      for(size_t j(0);j< squares[i].size(); j++)
	{
	  assert(squares[i][j]);
	  line+=squares[i][j]->getID(); 
	  line+=" "; 
	}
      writter << line << endl;
      line ="";
    }
}

void Editor::loadLevel(string path)
{
  string line="";
  ifstream reader(path.c_str());
  assert(m_level);
  vector<vector<Square*>> res; res.clear();
  if(reader.is_open())
    {
      while(getline(reader,line))
	{
	  string word = "" ;
	  vector<Square*> Sline; Sline.clear();
	  for(char letter:line)
	    {
	      if(letter!=' ' ){word+=letter;}
	      else
		{
		  if(word!="")
		    {
		      Sline.push_back(SquareFactory::getInstance()->get(word));
		      word="";
		    }
		}
	    }
	  res.push_back(Sline);
	}
      m_level->setSquares(res);
    }
  else
    {
      cout << " Couldn't open the file, please retry. \n";
    }
  
}

Editor::~Editor()
{

}
