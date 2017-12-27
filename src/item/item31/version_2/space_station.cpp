#include "space_station.h"
#include "asteroid.h"
#include "space_ship.h"
#include "collision_with_unknown_object.h"

CSpaceStation::CSpaceStation()
{
    initializeCollisionMap();
}

void CSpaceStation::collide(CGameObject& other_object)
{
    if (&other_object == this)
    {
        return;
    }

    CSpaceStation::HitFunctionPtr hfp = lookup(other_object);
    if (hfp)
    {
        (this->*hfp)(other_object);
    }
    else
    {
        throw CCollusionWithUnknownObject(other_object);
    }
}

void CSpaceStation::hitSpaceShip(const CGameObject& other_object)
{
    std::cout << "One \"Space Station\" collide with another \"Space ship\"." << std::endl;
}

void CSpaceStation::hitSpaceStation(const CGameObject& other_object)
{
    std::cout << "One \"Space Station\" collide with one \"Space station\"." << std::endl;
}

void CSpaceStation::hitAsteroid(const CGameObject& other_object)
{
    std::cout << "One \"Space Station\" collide with one \"Asteroid\"." << std::endl;
}

void CSpaceStation::initializeCollisionMap()
{
    m_hit_map[typeid(CSpaceShip).name()] = &CSpaceStation::hitSpaceShip;
    m_hit_map[typeid(CSpaceStation).name()] = &CSpaceStation::hitSpaceStation;
    m_hit_map[typeid(CAsteroid).name()] = &CSpaceStation::hitAsteroid;
}

CSpaceStation::HitFunctionPtr
CSpaceStation::lookup(const CGameObject& other_object)
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
