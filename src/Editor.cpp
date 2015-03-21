#include<Editor.hpp>

#include<Core.hpp>
#include<Graphics.hpp>
#include<Level.hpp>
#include<TextureEngine.hpp>
#include<SquareFactory.hpp>
#include<assert.h>

using namespace sf;

Editor::Editor(Core* core) :
  Scene(core)
{
  m_currentSquare=0;
  m_level=new Level(50,50);
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
    m_currentSquare = NB_SQUARE -1 ;
  }
} break;
	  case Keyboard::PageUp: {m_currentSquare++; m_currentSquare%=NB_SQUARE;} break;
	  }
      }break;
    case Event::MouseButtonPressed :
      {
	switch(event.key.code)
	  {
	  default : break;
	  case Mouse::Left : modifyTile(m_mouse.x/TILE_SIZE,m_mouse.y/TILE_SIZE); break;
	  }
      }break;
    default: break;
    }
}

void Editor::update(sf::Vector2f mouse)
{
  m_mouse = mouse ;
}

void Editor::draw(Graphics* g)
{
  assert(g);
  g->drawLevel(m_level);
}

void Editor::drawTileAtMouse(Graphics* g)
{
  assert(g);
  g->drawTile(m_mouse.x,m_mouse.y,SquareFactory::getInstance()->get(m_currentSquare));
}

void Editor::modifyTile(int x, int y)
{
  assert(m_level);
  m_level->modifyTile(x,y,SquareFactory::getInstance()->get(m_currentSquare));
}


Editor::~Editor()
{

}
