#include "asteroid.h"
#include "space_ship.h"
#include "game_object.h"
#include "space_station.h"
#include "collision_with_unknown_object.h"

void CAsteroid::collide(CGameObject& other_object)
{
    if (&other_object == this)
    {
        return;
    }
}

void CAsteroid::hitSpaceShip(const CSpaceShip& other_object)
{
    std::cout << "One \"Asteroid\" collide with another \"Space ship\"." << std::endl;
}

void CAsteroid::hitSpaceStation(const CSpaceStation& other_object)
{
    std::cout << "One \"Asteroid\" collide with one \"Space station\"." << std::endl;
}

void CAsteroid::hitAsteroid(const CAsteroid& other_object)
{
    std::cout << "One \"Asteroid\" collide with one \"Asteroid\"." << std::endl;
}
