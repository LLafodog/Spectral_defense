#include<Graphics.hpp>

#include<Game.hpp>
#include<Level.hpp>
#include<Square.hpp>
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

void Graphics::drawLevel(Level* lvl)
{
  assert(lvl && m_camera);
  m_window->clear(Color(4,139,154));
    
  if(lvl != m_currentLevel || m_currentLevel->hasChanged())
    {
      m_currentLevel = lvl;
      m_camera->setLevel(lvl);
      addLevel(lvl);
      lvl->setChanged(false);
    }
  m_window->draw(m_currentArray,TextureEngine::getInstance()->getTileset());
}

void Graphics::drawTile(int x, int y, Square* s)
{
  assert(s && m_window);
  VertexArray va(Quads);
  Vertex tile[4];
  // Position
  tile[0].position=Vector2f(x,y);
  tile[1].position=Vector2f(x+TILE_SIZE,y);
  tile[2].position=Vector2f(x+TILE_SIZE,y+TILE_SIZE);
  tile[3].position=Vector2f(x,y+TILE_SIZE);
  // texture
  TextureEngine* te = TextureEngine::getInstance();
  tile[0].texCoords=te->getCoords(s->getID()+"_tl");
  tile[1].texCoords=te->getCoords(s->getID()+"_tr");
  tile[2].texCoords=te->getCoords(s->getID()+"_br");
  tile[3].texCoords=te->getCoords(s->getID()+"_bl");

  for(size_t i(0);i<4;i++){va.append(tile[i]);}
  m_window->draw(va,TextureEngine::getInstance()->getTileset());
  
}

void Graphics::addLevel(Level* lvl)
{
  assert(lvl);
  auto squares = lvl->getSquares();
  m_currentArray.clear();
  for(size_t i(0);i<squares.size();i++)
    {
      for(size_t j(0);j<squares[i].size();j++)      
	{
	  Square* sq=squares[i][j];
	  assert(sq);
	  int x = j*TILE_SIZE,
	    y = i * TILE_SIZE;
	  Vertex tile[4];
	  // Position
	  tile[0].position=Vector2f(x,y);
	  tile[1].position=Vector2f(x+TILE_SIZE,y);
	  tile[2].position=Vector2f(x+TILE_SIZE,y+TILE_SIZE);
	  tile[3].position=Vector2f(x,y+TILE_SIZE);
	  // texture
	  TextureEngine* te = TextureEngine::getInstance();
	  tile[0].texCoords=te->getCoords(sq->getID()+"_tl");
	  tile[1].texCoords=te->getCoords(sq->getID()+"_tr");
	  tile[2].texCoords=te->getCoords(sq->getID()+"_br");
	  tile[3].texCoords=te->getCoords(sq->getID()+"_bl");

	  for(size_t i(0);i<4;i++){m_currentArray.append(tile[i]);}
	}
    }
}


Graphics::~Graphics()
{

}
