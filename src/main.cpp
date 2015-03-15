#include<SFML/Graphics/RenderWindow.hpp>
#include<Core.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,600),"Spectral_Defense");
  Core core(&window);
  core.run();

  return 0;
}
