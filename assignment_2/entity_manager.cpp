#include "entity_manager.hpp"
#include <algorithm>
#include <vector>

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
  // auto e = std::make_shared<Entity>(tag, m_totalEntitiesCreated++);
  auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntitiesCreated++));

  this->m_toAdd.push_back(e);
  return e;
}

void EntityManager::update()
{
  for (auto e : this->m_toAdd)
  {
    this->m_entityVector.push_back(e);
    this->m_entityMap[e->getTag()].push_back(e);
  }

  this->m_toAdd.clear();

  std::remove_if(
      this->m_entityVector.begin(),
      this->m_entityVector.end(),
      [](std::shared_ptr<Entity> x)
      {
        return !x->isAlive();
      });

  for (auto &v : this->m_entityMap)
  {
    std::remove_if(
        v.second.begin(),
        v.second.end(),
        [](std::shared_ptr<Entity> x)
        {
          return !x->isAlive();
        });
  }
}