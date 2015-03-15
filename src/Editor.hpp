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
  virtual void updateControl(sf::Event event);
  virtual void update();
  virtual void draw(Graphics* g);
  virtual ~Editor();

  protected:
    size_t currentSquare;
  Level* m_level;
};

#endif // EDITOR_HPP
