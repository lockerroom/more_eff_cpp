#ifndef COLLISION_WITH_UNKNOWN_OBJECT_H_
#define COLLISION_WITH_UNKNOWN_OBJECT_H_

#include "../../../common/common.h"

class CGameObject;

class CCollusionWithUnknownObject
{
public:
    CCollusionWithUnknownObject(const CGameObject& other_object);

public:
    const std::string& get_unknown_object_name() const;

private:
    std::string m_unknown_object_name;
};

#endif
