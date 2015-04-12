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
#include<Parser.hpp>

// debug
using namespace std;
#include<iostream>

using namespace sf;

Editor::Editor(Core* core) :
  Scene(core),
  m_level(15,15)
{
  m_currentSquare=0;
  m_mouse = Vector2f(-1,-1);
  m_generatorTileActivated = false;
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
	  case Keyboard::PageUp: 
	    {
	      m_currentSquare++; m_currentSquare%=SQUARES_ID.size();
	    } break;

	  case Keyboard::G : 
	    {
	      m_generatorTileActivated = !m_generatorTileActivated;
	    }
	  }
      }break;
    default: break;
    }

  if(Mouse::isButtonPressed(Mouse::Left)) modifyTile(m_mouse.x,m_mouse.y); 
  // Combinaison	    
  if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::S) ){saveLevel();}
  if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::L) ){cout << "Load which level ? \n ";string path;cin>>path; loadLevel(path);}
  if(Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::K) ){runConsole();}
}

void Editor::update(sf::Vector2f mouse)
{
  m_mouse = mouse ;
}

void Editor::runConsole()
{
  // TO DO 
  cout << " ====== Menu ===== \n" 
       << " 1) "<<endl;
}

void Editor::draw(Graphics* g)
{
  assert(g);
  g->drawLevel(&m_level,true);
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

  Square* s = SquareFactory::getInstance()->get(m_currentSquare);
  g->drawTile(xt,yt,s,s->getSize());
  delete s;
}

void Editor::modifyTile(int x, int y)
{
  Square* s = SquareFactory::getInstance()->get(m_currentSquare,x-x%TILE_SIZE,y-y%TILE_SIZE,m_generatorTileActivated);
    m_level.modifyTile(x,y,s);      
}


void Editor::saveLevel()
{
  string line="",name="";
  cout << " Name of level : " << endl;
  cin >> name;
  ofstream writter(TO_LEVEL_FOLDER+name.c_str(),ios::ate);
  auto squares =  m_level.getSquares();
  for(size_t i(0);i< squares.size(); i++)
    {
	  assert(squares[i]);
	  line+=squares[i]->getID();
	  if(squares[i]->isGenerator())line+='*';
	  line+=" "; 
	  if(i%m_level.getWidth()==0 && i!=0)
	    {
	      writter << line << endl;
	      line ="";
	    }
	  
    }
  writter.close();
}

void Editor::loadLevel(string path)
{
  string line="";
  ifstream reader(TO_LEVEL_FOLDER+path.c_str());
  vector<Square*> res; res.clear();
  int x = 0,
    y = 0;
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
		      res.push_back(SquareFactory::getInstance()->get(word,x,y));
		      word="";
		    }
		  x+=TILE_SIZE;
		}
	    }
	  y+=TILE_SIZE;
	  x=0;
	}
      m_level.setSquares(res);
    }
  else
    {
      cerr << " Couldn't open the file, please retry. \n";
    }
  
}

Editor::~Editor()
{
  m_level.free();
}
