#include<Core.hpp>

#include<SFML/Graphics.hpp>
#include<Graphics.hpp>
#include<Camera.hpp>
#include<TextureEngine.hpp>
#include<assert.h>

#include<Game.hpp>
#include<Menu.hpp>
#include<Editor.hpp>

#include<ctime>
// debug
#include<iostream>

using namespace sf;

Core::Core()
{
  m_window=new RenderWindow(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Spectral_Defense");
  init();
}

void Core::init()
{
  m_currentSceneIndex=0;
  m_clock.restart();
  m_scenes.clear();
  m_scenes.push_back(new Menu(this));
  m_scenes.push_back(new Game(this));
  // new scene before
  m_scenes.push_back(new Editor(this));
  m_graphics=new Graphics(m_window);
  m_currentScene=m_scenes[m_currentSceneIndex];
  TextureEngine::getInstance(); // load the textures 
}

void Core::run()
// game loop
{
  assert(m_window && m_currentScene);
  Event event;
  while(m_window->isOpen())
    {
      while(m_window->pollEvent(event))
	{
	  if(event.type == Event::Closed){quit();}
	  if(event.type == Event::KeyPressed 
	     && event.key.code == Keyboard::Escape)
	    {putScene(MENU);m_graphics->getCamera()->setDefaultView();}
	  m_currentScene->updateControl(event); 
	}
      update();
      draw();
    }
}


void Core::update()
{
  // FPS
  double dt = 1.0/(m_clock.restart().asMilliseconds()/1000.0);
  m_window->setTitle("Spectral_defense (FPS:"+to_string((int)dt)+")");
 
  assert(m_currentScene && m_window);
  if(m_currentScene->isRunning())
    {
      m_currentScene->update(m_window->mapPixelToCoords(Mouse::getPosition(*m_window)));
    }
  else
    {
      m_currentSceneIndex=min(m_scenes.size()-1,m_currentSceneIndex+1);
      m_currentScene=m_scenes[m_currentSceneIndex];
      m_currentScene->setRunning(true);
    }
}

void Core::putScene(size_t index)
{
  assert(index>=0 && index <NB_SCENE);
  m_currentScene = m_scenes[index];
  m_currentScene->setRunning(true);
}

void Core::restoreScene()
  {
    m_currentScene = m_scenes[m_currentSceneIndex];
  }

void Core::draw()
{
  assert(m_graphics && m_currentScene);
  m_currentScene->draw(m_graphics);
}
Core::~Core()
{
  for(Scene* s:m_scenes){delete s;}
  delete m_graphics;
  delete m_window;
}
