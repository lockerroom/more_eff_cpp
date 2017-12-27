#ifndef SPACE_STATION_H_
#define SPACE_STATION_H_

#include "../../../common/common.h"
#include "game_object.h"

class CSpaceShip;
class CSpaceStation;
class CAsteroid;

class CSpaceStation : public CGameObject
{
public:
    CSpaceStation();

public:
    virtual void collide(CGameObject&);
    virtual void hitSpaceShip(const CGameObject&);
    virtual void hitSpaceStation(const CGameObject&);
    virtual void hitAsteroid(const CGameObject&);

private:
    typedef void (CSpaceStation::*HitFunctionPtr)(const CGameObject&);
    typedef std::map<std::string, HitFunctionPtr> HitMap;

    HitMap m_hit_map;
    void initializeCollisionMap();
    HitFunctionPtr lookup(const CGameObject&);
};

#endif
