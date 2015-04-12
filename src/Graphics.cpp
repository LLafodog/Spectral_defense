#include<Graphics.hpp>

#include<Game.hpp>
#include<Level.hpp>
#include<Square.hpp>
#include<Defines.hpp>
#include<TextureEngine.hpp>
#include<Camera.hpp>

// debug
#include<iostream>

using namespace sf;

Graphics::Graphics(RenderWindow* window) :
  m_window(window)
{
  assert(window);
  m_currentArray = VertexArray(Quads);
  m_currentLevel=nullptr;
  m_camera = new Camera(m_window);
}

void Graphics::drawGame(Game* game)
{
  assert(m_window && game);
  Level* lvl = game->getCurrentLevel();
  drawLevel(lvl);
}

void Graphics::drawLevel(Level* lvl, bool editoringMode)
{
  assert(lvl && m_camera);
  m_window->clear(Color(0,128,0)); // Background Color

  if(lvl != m_currentLevel || m_currentLevel->hasChanged())
    {
      m_currentLevel = lvl;
      m_camera->setLevel(lvl);
      addLevel(lvl, true);
      lvl->setChanged(false);
    }
  m_window->draw(m_currentArray,TextureEngine::getInstance()->getTileset());
}

void Graphics::drawTile(int x, int y, Square* s, int size)
{
  assert(s && m_window);
  VertexArray va(Quads);
  Vertex tile[4];
  // Position
  tile[0].position=Vector2f(x,y);
  tile[1].position=Vector2f(x+size,y);
  tile[2].position=Vector2f(x+size,y+size);
  tile[3].position=Vector2f(x,y+size);
  // texture
  TextureEngine* te = TextureEngine::getInstance();
  tile[0].texCoords=te->getCoords(s->getID()+"_tl");
  tile[1].texCoords=te->getCoords(s->getID()+"_tr");
  tile[2].texCoords=te->getCoords(s->getID()+"_br");
  tile[3].texCoords=te->getCoords(s->getID()+"_bl");

  for(size_t i(0);i<4;i++){va.append(tile[i]);}
  m_window->draw(va,TextureEngine::getInstance()->getTileset());
  
}

void Graphics::addLevel(Level* lvl, bool editoringMode)
{
  assert(lvl);
  auto squares = lvl->getSquares();
  m_currentArray.clear();
  for(size_t i(0);i<squares.size();i++)
    {
      Square* s = squares[squares.size()-i-1];
      assert(s);
      int x = s->getX(),
	y = s->getY();
      Vertex tile[4];

      // Position
      tile[0].position=Vector2f(x,y);
      tile[1].position=Vector2f(x+s->getSize(),y);
      tile[2].position=Vector2f(x+s->getSize(),y+s->getSize());
      tile[3].position=Vector2f(x,y+s->getSize());

      // texture
      TextureEngine* te = TextureEngine::getInstance();
      tile[0].texCoords=te->getCoords(s->getID()+"_tl");
      tile[1].texCoords=te->getCoords(s->getID()+"_tr");
      tile[2].texCoords=te->getCoords(s->getID()+"_br");
      tile[3].texCoords=te->getCoords(s->getID()+"_bl");

      for(size_t i(0);i<4;i++)
	{
	  if(editoringMode && s->isGenerator()){tile[i].color = Color(128,0,0);}
	  m_currentArray.append(tile[i]);
	}
    }
}


Graphics::~Graphics()
{

}
