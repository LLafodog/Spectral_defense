#ifndef EDITOR_HPP
#define EDITOR_HPP

#include<Scene.hpp>
#include<SFML/Window/Event.hpp>

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
    short m_currentSquare;
  Level* m_level;
};

#endif // EDITOR_HPP
