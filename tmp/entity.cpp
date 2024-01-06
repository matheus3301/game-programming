#include "entity.hpp"
#include <stdint.h>

Entity::Entity(const std::string &tag, uint8_t id) : m_tag(tag), m_id(id) {}
const uint8_t &Entity::getId() const
{
  return this->m_id;
}
const std::string &Entity::getTag() const
{
  return this->m_tag;
}

bool Entity::isAlive() const
{
  return this->m_alive;
}

void Entity::destroy()
{
  this->m_alive = false;
}