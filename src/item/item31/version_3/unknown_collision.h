#ifndef COLLISION_WITH_UNKNOWN_OBJECT_H_
#define COLLISION_WITH_UNKNOWN_OBJECT_H_

#include "../../../common/common.h"

class CGameObject;

class CUnknownCollision
{
public:
    CUnknownCollision(const CGameObject& obj1, const CGameObject& obj2);

public:
    const std::pair<std::string, std::string>& get_unknown_objects_name() const;

private:
    std::pair<std::string, std::string> m_unknown_pair;
};

#endif
