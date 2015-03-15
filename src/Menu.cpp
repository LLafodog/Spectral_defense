#include<Menu.hpp>

#include<SFML/Graphics.hpp>
#include<assert.h>
#include<TextureEngine.hpp>

using namespace sf;

//debug
#include<iostream>
using namespace std;

enum CHOICE_LIST
  {
    PLAY,
    LOAD,
    OPTION,
    QUIT
  };

Menu::Menu()
{
  m_quit=false;
  m_activated=true;
  m_choice=0;
}

void Menu::update(Event event)
{
  switch(event.type)
    {
    default : break;
    case Event::Closed : m_quit=true;break;  
    case Event::KeyPressed:
      {
	switch(event.key.code)
	  {
	    //	  case Keyboard::Escape : m_quit=true;close(); break;
	  case Keyboard::Space : validate(); break;
	  case Keyboard::Down: {m_choice++; m_choice%=NB_CHOICE;}break;
	  case Keyboard::Up:
	    {
	      m_choice--;
	      if(m_choice<0){m_choice = NB_CHOICE;}
	    }break;
	  default : break;
	  }
      }break;
    }
}

void Menu::validate()
{
  switch(m_choice)
    {
    case PLAY :{close();}break;
    case LOAD :{}break;
    case OPTION :{} break;
    case QUIT:{m_quit=true;close();}
    }
}

void Menu::draw(RenderWindow* w)
{
  assert(w);
  int width = w->getView().getSize().x,
    height = w->getView().getSize().y;
  
  // TITLE
  w->clear(Color(4,139,154));
  VertexArray va(Quads);
  addBackground(va,width,height);
  addTitle(va, width, height);
  // draw()
  w->draw(va, TextureEngine::getInstance()->getMenuset());
  
  addButton(w,"Play",0);

  w->display();
}

void Menu::addBackground(sf::VertexArray& va, int w, int h) const
{
  Vertex background[4];
  // position
  background[0].position=Vector2f(0,0);
  background[1].position=Vector2f(w,0);
  background[2].position=Vector2f(w,h);
  background[3].position=Vector2f(0,h);
  // Texture
  // background[0].texCoords=TextureEngine::getInstance()->getCoords("menu_background_tl");
  // background[1].texCoords=TextureEngine::getInstance()->getCoords("menu_background_tr");
  // background[2].texCoords=TextureEngine::getInstance()->getCoords("menu_background_br");
  // background[3].texCoords=TextureEngine::getInstance()->getCoords("menu_background_bl");

  background[0].texCoords=Vector2f(900,200);
  background[1].texCoords=Vector2f(900,200);
  background[2].texCoords=Vector2f(900,200);
  background[3].texCoords=Vector2f(900,200);

  background[0].color=Color::White;
  background[1].color=Color(142,35,35);
  background[2].color=Color::Black;
  background[3].color=Color(104,34,139);
  // add
  for(size_t i(0);i<4;i++){va.append(background[i]);}

}

void Menu::addTitle(VertexArray& va, int w, int h) const
{
  Vertex title[4];
  // position
  title[0].position=Vector2f(0.1*w,0.1*h);
  title[1].position=Vector2f(0.8*w,0.1*h);
  title[3].position=Vector2f(0.1*w,0.2*h);
  title[2].position=Vector2f(0.8*w,0.2*h);
  // Texture
  title[0].texCoords=TextureEngine::getInstance()->getCoords("menu_title_tl");
  title[1].texCoords=TextureEngine::getInstance()->getCoords("menu_title_tr");
  title[2].texCoords=TextureEngine::getInstance()->getCoords("menu_title_br");
  title[3].texCoords=TextureEngine::getInstance()->getCoords("menu_title_bl");

  // add
  for(size_t i(0);i<4;i++){va.append(title[i]);}

}


void Menu::addButton(sf::RenderWindow* w, std::string text, short n_button) const
{
  assert(w);
  // data
  int w_width=w->getView().getSize().x,
    w_height=w->getView().getSize().y;

  int x = w_width*0.3,
    y = w_height*(0.3+n_button*0.1),
    button_width=w_width*0.6;


  // Font
  Font font;
  assert(font.loadFromFile(TO_FONT_FILE+DEFAULT_FONT.c_str()));

  // Texte
  Text tex(text,font,MENU_CHAR_SIZE);
  tex.setPosition(x,y);

  int tex_width=tex.getGlobalBounds().width+10,
    tex_height=tex.getCharacterSize()+10;

  VertexArray va(Quads);

  Vertex button[4];
  // position
  button[0].position=Vector2f(x,y);
  button[1].position=Vector2f(x+max(button_width,tex_width),y);
  button[2].position=Vector2f(x+max(button_width,tex_width),y+tex_height);
  button[3].position=Vector2f(x,y+tex_height);
  // Texture
  button[0].texCoords=TextureEngine::getInstance()->getCoords("menu_button_tl");
  button[1].texCoords=TextureEngine::getInstance()->getCoords("menu_button_tr");
  button[2].texCoords=TextureEngine::getInstance()->getCoords("menu_button_br");
  button[3].texCoords=TextureEngine::getInstance()->getCoords("menu_button_bl");

  // add
  for(size_t i(0);i<4;i++){va.append(button[i]);}

  w->draw(va,TextureEngine::getInstance()->getMenuset());
  w->draw(tex);



}

Menu::~Menu()
{

}
