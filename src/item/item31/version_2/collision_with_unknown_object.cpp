#include "collision_with_unknown_object.h"
#include "game_object.h"

CCollusionWithUnknownObject:: CCollusionWithUnknownObject(const CGameObject& other_object)
{
    const std::type_info& object_info = typeid(other_object);
    m_unknown_object_name = object_info.name();
}

const std::string& CCollusionWithUnknownObject::get_unknown_object_name() const
{
    return m_unknown_object_name;
}
