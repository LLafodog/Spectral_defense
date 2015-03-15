#ifndef MENU_HPP
#define MENU_HPP

#include<Scene.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<string>

const std::string DEFAULT_FONT="menu.ttf";
const std::string TO_FONT_FILE="../dat/font/";
const short MENU_CHAR_SIZE=48;


class Graphics;
class Core;

class Menu : public Scene
{
public:
  Menu(Core* core);
  void updateControl(sf::Event event);
  void draw(Graphics* g);
  void update(){}
  virtual ~Menu();

protected:
  void validate();
  void addBackground(sf::VertexArray& va, int w, int h) const;
  void addTitle(sf::VertexArray& va, int w, int h) const;
  void addButton(sf::RenderWindow* w, std::string text, short n_button) const;

  size_t m_choice;
  bool m_running;
  const short NB_CHOICE=3;
};

#endif // MENU_HPP
