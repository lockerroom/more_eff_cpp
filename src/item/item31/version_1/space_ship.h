#ifndef SPACE_SHIP_H_
#define SPACE_SHIP_H_

#include "../../../common/common.h"
#include "game_object.h"

class CSpaceShip : public CGameObject
{
public:
    virtual void collide(CGameObject&);
};

#endif
