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
  m_tileCoords.insert(pair<string,Vector2f>("menu_title_tl",Vector2f(0,0)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_title_tr",Vector2f(1000,0)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_title_bl",Vector2f(0,147)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_title_br",Vector2f(1000,147)));
  //background
  m_tileCoords.insert(pair<string,Vector2f>("menu_background_tl",Vector2f(0,150)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_background_tr",Vector2f(50,150)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_background_bl",Vector2f(0,200)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_background_br",Vector2f(50,200)));
  // button
  m_tileCoords.insert(pair<string,Vector2f>("menu_button_tl",Vector2f(0,300)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_button_tr",Vector2f(1000,300)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_button_bl",Vector2f(0,450-6)));
  m_tileCoords.insert(pair<string,Vector2f>("menu_button_br",Vector2f(1000,450-6)));
 
}

TextureEngine* TextureEngine::getInstance()
{
  if(m_self==nullptr){m_self=new TextureEngine();}
  return m_self;
}

TextureEngine::~TextureEngine()
{

}
