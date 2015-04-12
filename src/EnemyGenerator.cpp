#include<EnemyGenerator.hpp>

#include<iostream>

EnemyGenerator::EnemyGenerator(string id, float x, float y, float size) : Square(id,x,y,size)
{
  m_path = true;
}

void EnemyGenerator::update()
{
      cout << " Bitch ! " << endl;
}

EnemyGenerator::~EnemyGenerator()
{

}
