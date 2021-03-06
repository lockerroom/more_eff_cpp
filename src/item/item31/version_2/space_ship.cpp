#include "space_ship.h"
#include "asteroid.h"
#include "game_object.h"
#include "space_station.h"
#include "collision_with_unknown_object.h"

CSpaceShip::CSpaceShip()
{
    initializeCollisionMap();
}

void CSpaceShip::collide(CGameObject& other_object)
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

void CSpaceShip::hitSpaceShip(const CGameObject& other_object)
{
    std::cout << "One \"Space ship\" collide with another \"Space ship\"." << std::endl;
}

void CSpaceShip::hitSpaceStation(const CGameObject& other_object)
{
    const CSpaceStation& space_station = dynamic_cast<const CSpaceStation&>(other_object);
    std::cout << "One \"Space ship\" collide with one \"Space station\"." << std::endl;
}

void CSpaceShip::hitAsteroid(const CGameObject& other_object)
{
    std::cout << "One \"Space ship\" collide with one \"Asteroid\"." << std::endl;
}

void CSpaceShip::initializeCollisionMap()
{
    // Method one, use reinterpert_cast
    // Method two, make all functions' parameter accept CGameObject, and use dynamic_cast
    m_hit_map[typeid(CSpaceShip).name()] = &CSpaceShip::hitSpaceShip;
    m_hit_map.insert(std::make_pair(std::string(typeid(CSpaceStation).name()), &CSpaceShip::hitSpaceStation));
    m_hit_map.insert(std::make_pair(std::string(typeid(CAsteroid).name()), &CSpaceShip::hitAsteroid));
}

CSpaceShip::HitFunctionPtr
CSpaceShip::lookup(const CGameObject& object)
{
    // std::cout << typeid(object).name() << std::endl;
    HitMap::const_iterator cit = m_hit_map.find(typeid(object).name());
    if (cit == m_hit_map.cend())
    {
        return 0;
    }
    else 
    {
        return (*cit).second;
    }
}
