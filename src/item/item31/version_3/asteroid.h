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
    CAsteroid();

public:
    virtual void collide(CGameObject&);
    virtual void hitSpaceShip(const CGameObject&);
    virtual void hitSpaceStation(const CGameObject&);
    virtual void hitAsteroid(const CGameObject&);

private:
    typedef void (CAsteroid::*HitFunctionPtr)(const CGameObject&);
    typedef std::map<std::string, HitFunctionPtr> HitMap;

    HitMap m_hit_map;
    void initializeCollisionMap();
    HitFunctionPtr lookup(const CGameObject&);
};

#endif
