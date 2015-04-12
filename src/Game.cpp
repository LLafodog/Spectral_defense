#include<Game.hpp>
#include<Level.hpp>
#include<assert.h>
#include<Graphics.hpp>
#include<Core.hpp>
using namespace sf;

Game::Game(Core* core) :
  Scene(core)
{
  m_running=false;
  m_levels.clear();
  addLevels();
  m_currentLevel=0;
}

void Game::addLevels()
{
  m_levels.push_back(Level("gene"));
}


void Game::updateControl(Event event)
{
  assert(m_core);
  switch(event.type)
    {
    default: break;
    case Event::KeyPressed:
      {
	switch(event.key.code)
	  {
	  default:break;
	  }
      }break;
    }
}

void Game::update(sf::Vector2f mouse)
{
  m_levels[m_currentLevel].update();
}

void Game::draw(Graphics* g)
{
  assert(g);
  g->drawGame(this);
  g->display();
}

Game::~Game()
{
  for(Level  lvl : m_levels)
    {
      lvl.free ();
    }
}
