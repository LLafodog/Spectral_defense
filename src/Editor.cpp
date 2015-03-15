#include<Editor.hpp>

#include<Core.hpp>
#include<Graphics.hpp>
#include<Level.hpp>
#include<assert.h>

using namespace sf;

Editor::Editor(Core* core) :
  Scene(core)
{
  m_currentSquare=0;
  m_level=new Level(50,50);
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
	  case Keyboard::PageDown: break;
	  case Keyboard::PageUp: break;
	  }
      }break;
    default: break;
    }
}

void Editor::update(sf::Vector2f mouse)
{
  
}

void Editor::draw(Graphics* g)
{
  assert(g);
  g->drawLevel(m_level);
}

Editor::~Editor()
{

}
