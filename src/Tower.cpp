#include<Tower.hpp>

#include<Square.hpp>
#include<assert.h>

using namespace std;
// test

Tower::Tower(Square* s, string id):
  m_square(s),
  m_id(id)
{
  assert(s);
}



Tower::~Tower()
{

}
