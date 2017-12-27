#include "game.h"
#include "version_2/asteroid.h"
#include "version_2/space_ship.h"
#include "version_2/space_station.h"

void CGame::start_game()
{
    CSpaceShip space_ship;
    CSpaceStation space_station;
    CAsteroid asteroid;

    space_ship.collide(space_station);
    space_ship.collide(asteroid);

    // space_station.collide(space_ship);
    // space_station.collide(asteroid);

    // asteroid.collide(space_ship);
    // asteroid.collide(space_station);
}
