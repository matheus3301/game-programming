#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>
#include <map>
#include <memory>
#include <string>

#include "entity.hpp"

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<std::string, EntityVector> EntityMap;

class EntityManager
{
  EntityVector m_entityVector;
  EntityMap m_entityMap;

  EntityVector m_toAdd;

  uint8_t m_totalEntitiesCreated = 0;

public:
  EntityManager();
  std::shared_ptr<Entity> addEntity(const std::string &tag);
  void update();
  EntityVector &getEntities() const;
  EntityVector &getEntities(const std::string &tag) const;
};

#endif