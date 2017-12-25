#ifndef SPACE_STATION_H_
#define SPACE_STATION_H_

#include "../../../common/common.h"
#include "game_object.h"

class CSpaceStation : public CGameObject
{
public:
    virtual void collide(CGameObject&);
};

#endif
