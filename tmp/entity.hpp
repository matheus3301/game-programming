#ifndef ENTITY
#define ENTITY

#include <string>

class Entity
{
  const uint8_t m_id = 0;
  const std::string m_tag = "Default";
  bool m_alive = true;
  Entity(const std::string &tag, uint8_t id);

public:
  const uint8_t &getId() const;
  const std::string &getTag() const;
  bool isAlive() const;
  void destroy();

  friend class EntityManager;
};

#endif