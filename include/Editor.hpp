#ifndef EDITOR_HPP
#define EDITOR_HPP

#include<Scene.hpp>

#include<SFML/Window/Event.hpp>
#include<SFML/Graphics/View.hpp>
#include<SFML/System/Vector2.hpp>
#include<string>

class Core;
class Graphics;
class Level;

class Editor : public Scene
{
public:

  Editor(Core* core);
  void updateControl(sf::Event event);
  void update(sf::Vector2f mouse);
  void draw(Graphics* g);
  virtual ~Editor();

  protected:
  void drawTileAtMouse(Graphics* g);
  void modifyTile(int x, int y);
  void saveLevel();
  void loadLevel(std::string path);

    short m_currentSquare;
  Level* m_level;
  sf::Vector2f m_mouse;
bool m_viewDirection[4];
};

#endif // EDITOR_HPP
