#include "unknown_collision.h"
#include "game_object.h"

CUnknownCollision:: CUnknownCollision(const CGameObject& obj1, const CGameObject& obj2)
{
    m_unknown_pair = std::make_pair(typeid(obj1).name(), typeid(obj2).name());
}

const std::pair<std::string, std::string>& CUnknownCollision::get_unknown_objects_name() const
{
    return m_unknown_pair;
}
