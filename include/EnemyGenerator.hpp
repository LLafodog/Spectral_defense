#ifndef ENEMYBASE_HPP 
#define ENEMYBASE_HPP 
 
#include<Square.hpp>
#include<string>

using namespace std;

class EnemyGenerator : public Square
{ 
public : 
  EnemyGenerator(string id, float x = 0, float y = 0, float size = TILE_SIZE);
  void update();
  inline EnemyGenerator* getCopy() {return new EnemyGenerator(*this);}
  inline bool isGenerator() const {return true;}
  virtual ~EnemyGenerator(); 
  
protected: 

};

#endif // ENEMYBASE_HPP
