#include<Menu.hpp>

#include<SFML/Graphics.hpp>
#include<Graphics.hpp>
#include<assert.h>
#include<TextureEngine.hpp>
#include<Core.hpp>

using namespace sf;

//debug
#include<iostream>
using namespace std;

const int BUTTON_X=0.3*WINDOW_WIDTH;
const int BUTTON_WIDTH=0.3*WINDOW_WIDTH;

enum CHOICE_LIST
  {
    PLAY,
    LOAD,
    OPTION,
    EDITOR,
    QUIT,
    NB_CHOICE
  };

Menu::Menu(Core* core):
  Scene(core)
{
  m_running=true;
  m_choice=0;
}

void Menu::updateControl(Event event)
{
  assert(m_core);
  switch(event.type)
    {
    default : break;
    case Event::Closed : m_core->quit();break;  
    case Event::MouseButtonPressed:
      {
	switch(event.key.code)
	  {
	  default:break;
	  case Mouse::Left: validate();break;
	  }
      }
    case Event::KeyPressed:
      {
	switch(event.key.code)
	  {
	  case Keyboard::Return: validate(); break;
	  case Keyboard::Down: {m_choice++; m_choice%=NB_CHOICE;}break;
	  case Keyboard::Up:
	    {
	      m_choice--;
	      if(m_choice>NB_CHOICE){m_choice = NB_CHOICE-1;}
	    }break;
	  default : break;
	  }
      }break;
    }
}

void Menu::update(sf::Vector2f mouse)
{
  for(size_t i(0);i<NB_CHOICE;i++)
    {
      double button_y = 0.3*WINDOW_HEIGHT+(0.05*WINDOW_HEIGHT+MENU_CHAR_SIZE*1.5)*i;
      FloatRect button(BUTTON_X,button_y, BUTTON_WIDTH,0.05*WINDOW_HEIGHT+MENU_CHAR_SIZE); 
      if(button.contains(mouse.x,mouse.y))m_choice=i;
    }
}

void Menu::validate()
{
  assert(m_core);
  switch(m_choice)
    {
    case PLAY :{m_active=false; m_core->restoreScene();}break;
    case LOAD :{}break;
    case OPTION :{} break;
    case EDITOR:{m_core->putScene(EDITION);} break;
    case QUIT:{m_core->quit();}
    default:assert(false);break;
    }
}

void Menu::draw(Graphics* g)
{
  assert(g);
  RenderWindow* w=g->getWindow();
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
  addButton(w,"Load",1);
  addButton(w,"Option",2);
  addButton(w,"Editor",3);
  addButton(w,"Quit",4);

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
  title[1].position=Vector2f(0.9*w,0.1*h);
  title[3].position=Vector2f(0.1*w,0.2*h);
  title[2].position=Vector2f(0.9*w,0.2*h);
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
  int w_width=WINDOW_WIDTH,
    w_height=WINDOW_HEIGHT;

  int x = BUTTON_X,
    y = w_height*0.3; 


  // Font
  Font font;
  assert(font.loadFromFile(TO_FONT_FILE+DEFAULT_FONT.c_str()));

  // Texte
  Text tex(text,font,MENU_CHAR_SIZE);
  tex.setColor(Color::Red);
  int tex_width=tex.getGlobalBounds().width,
    tex_height=tex.getCharacterSize()+MENU_CHAR_SIZE/2,
    tex_x = (x+BUTTON_WIDTH/2-tex_width/2);

  y+=n_button*(tex_height+0.05*w_height);
  tex.setPosition(tex_x,y);


  /// Drawing the button
  VertexArray va(Quads);
  Vertex button[4];
  // position
  button[0].position=Vector2f(x,y);
  button[1].position=Vector2f(x+max(BUTTON_WIDTH,tex_width),y);
  button[2].position=Vector2f(x+max(BUTTON_WIDTH,tex_width),y+tex_height);
  button[3].position=Vector2f(x,y+tex_height);
  // Color if Selected
  if(n_button==m_choice)
    {
      Color selection = Color(250,050,150);
      for(size_t i(0);i<4;i++){button[i].color=selection;}
    }

  // Texture
  button[0].texCoords=TextureEngine::getInstance()->getCoords("menu_button_tl");
  button[1].texCoords=TextureEngine::getInstance()->getCoords("menu_button_tr");
  button[2].texCoords=TextureEngine::getInstance()->getCoords("menu_button_br");
  button[3].texCoords=TextureEngine::getInstance()->getCoords("menu_button_bl");
  // add
  for(size_t i(0);i<4;i++){va.append(button[i]);}

  // Drawing
  w->draw(va,TextureEngine::getInstance()->getMenuset());
  w->draw(tex);



}

Menu::~Menu()
{
  
}
