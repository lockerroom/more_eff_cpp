#ifndef REGISTER_COLLISION_H_
#define REGISTER_COLLISION_H_

#include "../../../common/common.h"
#include "collison_map.h"

class CRegisterCollisionFunctions
{
public:
    CRegisterCollisionFunctions(const std::string&, 
                                const std::string&, 
                                CCollisionMap::HitFunctionPtr,
                                bool symmetric = true);
};

#endif
