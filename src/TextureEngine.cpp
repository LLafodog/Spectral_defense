#include<TextureEngine.hpp>

#include<assert.h>
#include<Defines.hpp>

TextureEngine* TextureEngine::m_self=nullptr;

// debug
#include<iostream>
//

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
  for(size_t i(0);i<SQUARES_ID.size();i++)
    {
      int size = 128;     
      addSquare(SQUARES_ID[i],128*(i%4),128*(i/4),size,size);
    }
  addSquare("grass",0,0,0,0);


  // MENU
  addSquare("menu_title",0,0,1000,147);
  addSquare("menu_background",0,150,50,50);
  addSquare("menu_button",0,200,1000,150);
}

void TextureEngine::addSquare(string name, int x, int y, int w, int h)
{
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
