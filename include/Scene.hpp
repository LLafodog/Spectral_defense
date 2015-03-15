#ifndef SCENE_HPP
#define SCENE_HPP

#include<SFML/Window/Event.hpp>

class Core;
class Graphics;

class Scene
{

public : 
  Scene(Core* core);
  inline virtual bool isRunning() {return m_active;}
  inline void setRunning(bool b) {m_active=b;}
  virtual void updateControl(sf::Event event)=0;
  virtual void update(sf::Vector2f mouse)=0;
  virtual void draw(Graphics* g)=0;
  virtual ~Scene();

protected:
  bool m_active;
  Core* m_core;
};

#endif // SCENE_HPP
