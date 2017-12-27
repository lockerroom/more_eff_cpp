#include "asteroid.h"
#include "space_ship.h"
#include "game_object.h"
#include "space_station.h"
#include "collision_with_unknown_object.h"

CAsteroid::CAsteroid()
{
    initializeCollisionMap();
}

void CAsteroid::collide(CGameObject& other_object)
{
    if (&other_object == this)
    {
        return;
    }

    HitFunctionPtr hfp = lookup(other_object);
    if (hfp)
    {
        (this->*hfp)(other_object);
    }
    else
    {
        throw CCollusionWithUnknownObject(other_object);
    }
}

void CAsteroid::hitSpaceShip(const CGameObject& other_object)
{
    std::cout << "One \"Asteroid\" collide with another \"Space ship\"." << std::endl;
}

void CAsteroid::hitSpaceStation(const CGameObject& other_object)
{
    std::cout << "One \"Asteroid\" collide with one \"Space station\"." << std::endl;
}

void CAsteroid::hitAsteroid(const CGameObject& other_object)
{
    std::cout << "One \"Asteroid\" collide with one \"Asteroid\"." << std::endl;
}

void CAsteroid::initializeCollisionMap()
{
    m_hit_map[typeid(CSpaceShip).name()] = &CAsteroid::hitSpaceShip;
    m_hit_map[typeid(CSpaceStation).name()] = &CAsteroid::hitSpaceStation;
    m_hit_map[typeid(CAsteroid).name()] = &CAsteroid::hitAsteroid;
}

CAsteroid::HitFunctionPtr
CAsteroid::lookup(const CGameObject& other_object)
{
    const std::type_info& object_type = typeid(other_object);

    HitMap::const_iterator cit = m_hit_map.find(object_type.name());
    if (cit == m_hit_map.cend())
    {
        return 0;
    }
    else
    {
        return (*cit).second;
    }
}

