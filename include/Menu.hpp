#ifndef MENU_HPP
#define MENU_HPP

#include<SFML/Window/Event.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<string>

const std::string DEFAULT_FONT="menu.ttf";
const std::string TO_FONT_FILE="../dat/font/";
const short MENU_CHAR_SIZE=48;


class Graphics;

class Menu
{
public:
  Menu();
  void update(sf::Event event);
  void draw(sf::RenderWindow* w);
  inline bool isActive() {return m_activated;}
  inline void setActive(bool b) {m_activated=b; m_quit=false;}
  inline bool mustQuit() {return m_quit;}
  virtual ~Menu();

protected:
  inline void close() {m_activated=false;}
  void validate();
  void addBackground(sf::VertexArray& va, int w, int h) const;
  void addTitle(sf::VertexArray& va, int w, int h) const;
  void addButton(sf::RenderWindow* w, std::string text, short n_button) const;

  size_t m_choice;
  bool m_activated;
  bool m_quit;
  const short NB_CHOICE=3;
};

#endif // MENU_HPP
