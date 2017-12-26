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

    const std::type_info& other_type = typeid(other_object);
    if (typeid(CSpaceShip) == other_type)
    {
        std::cout << "One \"Asteroid\" collide with another \"Space ship\"." << std::endl;
    }
    else if (typeid(CSpaceStation) == other_type)
    {
        std::cout << "One \"Asteroid\" collide with one \"Space station\"." << std::endl;
    }
    else if (typeid(CAsteroid) == other_type)
    {
        std::cout << "One \"Asteroid\" collide with one \"Asteroid\"." << std::endl;
    }
    else
    {
        throw CCollusionWithUnknownObject(other_object);
    }
}
