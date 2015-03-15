#include<Core.hpp>

#include<SFML/Graphics.hpp>
#include<Graphics.hpp>
#include<TextureEngine.hpp>
#include<assert.h>
#include<Level.hpp>
#include<Menu.hpp>

#include<ctime>
// debug
#include<iostream>

using namespace sf;

Core::Core(RenderWindow* w) :
  m_window(w),
  m_currentLevel(0)
{
  assert(w);
  m_graphics=new Graphics(w);
  init();
}

void Core::init()
{
  m_clock.restart();
  m_levels.clear();
  addLevels();
  m_menu=new Menu();

  TextureEngine::getInstance(); // load the textures 
}

void Core::addLevels()
{
  m_levels.push_back(Level("test"));
}

void Core::run()
// game loop
{
  assert(m_window && m_menu);
  Event event;
  while(m_window->isOpen())
    {
      while(m_window->pollEvent(event))
	{
	  // Menu ?
	  if(m_menu->isActive())
	    {
	      m_menu->update(event);
	      m_menu->draw(m_window);
	      if(m_menu->mustQuit()){m_window->close();}
	    }
	  else
	    {
	      gameControl(event);
	    }
	}
      if(!m_menu->isActive())
	{
	  update();
	  draw();
	}

    }
}

void Core::gameControl(Event event)
{
  switch(event.type)
    {
    default: break;
    case Event::Closed : m_window->close();break;
    case Event::KeyPressed:
      {
	switch(event.key.code)
	  {
	  case Keyboard::Escape : m_menu->setActive(true);break;
	  default:break;
	  }
      }break;
    }

}

void Core::update()
{
  double dt = 1.0/(m_clock.restart().asMilliseconds()/1000.0);
  m_window->setTitle("Spectral_defense (FPS:"+to_string((int)dt)+")");
}

void Core::draw()
{
  assert(m_graphics);
  m_graphics->draw(&m_levels[m_currentLevel]);
}
Core::~Core()
{
  delete m_graphics;
  delete m_menu;
}
