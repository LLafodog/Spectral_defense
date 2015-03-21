#include<TextureEngine.hpp>

#include<assert.h>
TextureEngine* TextureEngine::m_self=nullptr;

using namespace std;

TextureEngine::TextureEngine()
{
  assert(load());
}

bool TextureEngine::load()
{
  m_tileCoords.clear();
  if(
     !m_tileset.loadFromFile(TO_IMG_FOLDER+"tileset.png")
     || !m_menuset.loadFromFile(TO_IMG_FOLDER+"menuset.png")
     
     ){return false;}  
  
  addCoords();
  return true;
}

void TextureEngine::addCoords()
{
  // GRASS
  m_tileCoords.insert(pair<string,Vector2f>("grass_tl",Vector2f(0,0)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_t",Vector2f(TILE_SIZE,0)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_tr",Vector2f(2*TILE_SIZE,0)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_l",Vector2f(0,TILE_SIZE)));
  m_tileCoords.insert(pair<string,Vector2f>("grass",Vector2f(TILE_SIZE*3,TILE_SIZE*3)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_r",Vector2f(TILE_SIZE*2,TILE_SIZE)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_bl",Vector2f(0,2*TILE_SIZE)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_b",Vector2f(TILE_SIZE,2*TILE_SIZE)));
  m_tileCoords.insert(pair<string,Vector2f>("grass_br",Vector2f(2*TILE_SIZE,2*TILE_SIZE)));

  // MENU
  //title
  addSquare("menu_title",0,0,1000,147);
  //background
  addSquare("menu_background",0,150,50,50);
  // button
  addSquare("menu_button",0,200,1000,150);
}

void TextureEngine::addSquare(string name, int x, int y, int w, int h)
{
  // WORKING
  m_tileCoords.insert(pair<string,Vector2f>(name+"_tl",Vector2f(x,y)));
  m_tileCoords.insert(pair<string,Vector2f>(name+"_tr",Vector2f(x+w,y)));
  m_tileCoords.insert(pair<string,Vector2f>(name+"_bl",Vector2f(x,y+h)));
  m_tileCoords.insert(pair<string,Vector2f>(name+"_br",Vector2f(x+w,y+h)));
}
TextureEngine* TextureEngine::getInstance()
{
  if(m_self==nullptr){m_self=new TextureEngine();}
  return m_self;
}

TextureEngine::~TextureEngine()
{

}
