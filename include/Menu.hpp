#ifndef MENU_HPP
#define MENU_HPP

#include<Scene.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<SFML/System/Vector2.hpp>
#include<string>

const std::string DEFAULT_FONT="menu.ttf";
const std::string TO_FONT_FILE="../dat/font/";


class Graphics;
class Core;

class Menu : public Scene
{
public:
  Menu(Core* core);
  void updateControl(sf::Event event);
  void draw(Graphics* g);
  void update(sf::Vector2f mouse);
  virtual ~Menu();

protected:
  void validate();
  void addBackground(sf::VertexArray& va, int w, int h) const;
  void addTitle(sf::VertexArray& va, int w, int h) const;
  void addButton(sf::RenderWindow* w, std::string text, short n_button);

  sf::Vector2f m_mouse;
  size_t m_choice;
  bool m_running;
};

#endif // MENU_HPP
