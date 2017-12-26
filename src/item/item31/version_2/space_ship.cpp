#include "space_ship.h"
#include "asteroid.h"
#include "game_object.h"
#include "space_station.h"
#include "collision_with_unknown_object.h"

CSpaceShip::HitFunctionPtr
CSpaceShip::lookup(const CGameObject& object)
{
    static HitMap collisionMap;
    

    HitMap::const_iterator cit = collisionMap.find(typeid(object).name());
    if (cit == collisionMap.cend())
    {
        return 0;
    }
    else 
    {
        return (*cit).second;
    }
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

    /*
    const std::type_info& other_type = typeid(other_object);
    if (typeid(CSpaceShip) == other_type)
    {
        std::cout << "One \"Space ship\" collide with another \"Space ship\"." << std::endl;
    }
    else if (typeid(CSpaceStation) == other_type)
    {
        std::cout << "One \"Space ship\" collide with one \"Space station\"." << std::endl;
    }
    else if (typeid(CAsteroid) == other_type)
    {
        std::cout << "One \"Space ship\" collide with one \"Asteroid\"." << std::endl;
    }
    else
    {
        throw CCollusionWithUnknownObject(other_object);
    }
    */
}

void CSpaceShip::hitSpaceShip(const CSpaceShip& other_object)
{
    std::cout << "One \"Space ship\" collide with another \"Space ship\"." << std::endl;
}

void CSpaceShip::hitSpaceStation(const CSpaceStation& other_object)
{
    std::cout << "One \"Space ship\" collide with one \"Space station\"." << std::endl;
}

void CSpaceShip::hitAsteroid(const CAsteroid& other_object)
{
    std::cout << "One \"Space ship\" collide with one \"Asteroid\"." << std::endl;
}
