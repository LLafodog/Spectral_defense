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
  m_view= View(
	 Vector2f(m_level->getWidth()/2*TILE_SIZE,m_level->getHeight()/2*TILE_SIZE),
	 Vector2f(12*TILE_SIZE,10*TILE_SIZE)
	 );
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
  g->setView(m_view);
  g->drawLevel(m_level);
  drawTileAtMouse(g);
  g->display();
}

void Editor::drawTileAtMouse(Graphics* g)
{
  assert(g);
  int xt=m_mouse.x-TILE_SIZE/3;
  xt -= xt%TILE_SIZE;
  int yt=m_mouse.y-TILE_SIZE/3;
  yt-=yt%TILE_SIZE;
  g->drawTile(xt,yt,SquareFactory::getInstance()->get(m_currentSquare));
}

void Editor::modifyTile(int x, int y)
{
  assert(m_level);
  m_level->modifyTile(x,y,SquareFactory::getInstance()->get(m_currentSquare));
}


Editor::~Editor()
{

}
