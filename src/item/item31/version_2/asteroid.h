#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "../../../common/common.h"
#include "game_object.h"

class CSpaceShip;
class CSpaceStation;
class CAsteroid;

class CAsteroid : public CGameObject
{
public:
    virtual void collide(CGameObject&);
    virtual void hitSpaceShip(const CSpaceShip&);
    virtual void hitSpaceStation(const CSpaceStation&);
    virtual void hitAsteroid(const CAsteroid&);
};

#endif
