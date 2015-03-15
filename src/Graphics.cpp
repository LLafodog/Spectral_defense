#include<Graphics.hpp>

#include<Level.hpp>
#include<Square.hpp>
#include<TextureEngine.hpp>
#include<assert.h>

// debug
#include<iostream>

using namespace sf;

Graphics::Graphics(RenderWindow* window) :
  m_window(window)
{
  assert(window);
  m_view=View(Vector2f(0,0),Vector2f(10,10));
}

void Graphics::draw(Level* lvl)
{
  assert(m_window && lvl);
  m_window->clear(Color(4,139,154));
    
  VertexArray va(Quads);
  addLevel(lvl,va);

  int width = lvl->getWidth() * TILE_SIZE,
    height = lvl->getHeight() * TILE_SIZE;

  if(m_view.getCenter().x==0)
    {
      m_view.setSize(Vector2f(width/2,height/2));
      m_view.setCenter(Vector2f(width/2,height/2));
    }
  //    m_window->setView(m_view);

  m_window->draw(va,TextureEngine::getInstance()->getTileset());

  m_window->display();
}

void Graphics::addLevel(Level* lvl, VertexArray& va)
{
  assert(lvl);
  auto squares = lvl->getSquares();
  for(size_t i(0);i<squares.size();i++)
    {
      for(size_t j(0);j<squares[i].size();j++)      
	{
	  Square* sq=squares[i][j];
	  assert(sq);

	  Vertex v1; 
	  v1.position=Vector2f(j*TILE_SIZE,i*TILE_SIZE);
	  v1.texCoords=TextureEngine::getInstance()->getCoords(sq->getID());

	  Vertex v2; 
	  v2.position=Vector2f((j+1)*TILE_SIZE,i*TILE_SIZE);
	  v2.texCoords=v1.texCoords+Vector2f(TILE_SIZE,0);


	  Vertex v3; 
	  v3.position=Vector2f((1+j)*TILE_SIZE,(1+i)*TILE_SIZE);
	  v3.texCoords=v1.texCoords+Vector2f(TILE_SIZE,TILE_SIZE);

	  Vertex v4; 
	  v4.position=Vector2f(j*TILE_SIZE,(1+i)*TILE_SIZE);
	  v4.texCoords=v1.texCoords+Vector2f(0,TILE_SIZE);

	  va.append(v1);
	  va.append(v2);
	  va.append(v3);
	  va.append(v4);
	}
    }
}

Graphics::~Graphics()
{

}
