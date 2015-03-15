#include<Scene.hpp>
#include<Core.hpp>
#include<assert.h>

Scene::Scene(Core* core):
  m_core(core)
{
  assert(core);
}

Scene::~Scene()
  {

  }
