#ifndef GAME_HPP
#define GAME_HPP

#include<Scene.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<vector>
#include<Level.hpp>
using namespace std;

class Game : public Scene
{
public:
  Game(Core* core);
  // Scene
  void updateControl(sf::Event event);
  inline Level* getCurrentLevel() {return &m_levels[m_currentLevel];}
  void update();
  void draw(Graphics* g);

  virtual ~Game();

protected:
  void addLevels();

  vector<Level> m_levels;
  int m_currentLevel;
bool m_running;

};

#endif // GAME_HPP
