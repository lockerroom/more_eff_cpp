#include "space_station.h"
#include "asteroid.h"
#include "space_ship.h"
#include "collision_with_unknown_object.h"

void CSpaceStation::collide(CGameObject& other_object)
{
    if (&other_object == this)
    {
        return;
    }
}

void CSpaceStation::hitSpaceShip(const CSpaceShip& other_object)
{
    std::cout << "One \"Space Station\" collide with another \"Space ship\"." << std::endl;
}

void CSpaceStation::hitSpaceStation(const CSpaceStation& other_object)
{
    std::cout << "One \"Space Station\" collide with one \"Space station\"." << std::endl;
}

void CSpaceStation::hitAsteroid(const CAsteroid& other_object)
{
    std::cout << "One \"Space Station\" collide with one \"Asteroid\"." << std::endl;
}
