#ifndef TEXTUREENGINE_HPP
#define TEXTUREENGINE_HPP

#include<string>
#include<SFML/Graphics.hpp>
#include<map>
using namespace sf;
using namespace std;

static const std::string TO_IMG_FOLDER="../dat/img/";
static const short TILE_SIZE=32;

class TextureEngine
{
public:

  static TextureEngine* getInstance();
  inline Vector2f getCoords(string id){return m_tileCoords[id];}
  inline Texture* getTileset() {return &m_tileset;}
  inline Texture* getMenuset() {return &m_menuset;}

  virtual ~TextureEngine();

protected:
  TextureEngine();
  bool load();

  void addLine(string name, int nb_x, int width, int height);
  void addSquare(string name, int x, int y, int w, int h);
  void addCoords();
  static TextureEngine* m_self;
  
  Texture m_tileset;
  Texture m_menuset;
  map<string,Vector2f> m_tileCoords;
};

#endif // TEXTUREENGINE_HPP
