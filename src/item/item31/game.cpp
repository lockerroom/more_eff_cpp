#include "game.h"
// #include "version_2/asteroid.h"
// #include "version_2/space_ship.h"
// #include "version_2/space_station.h"
#include "version_3/collision_process.h"

void CGame::start_game()
{
    CSpaceShip space_ship;
    CSpaceStation space_station;
    CAsteroid asteroid;

    std::cout << typeid(space_ship).name() << std::endl;
    process_collision(space_ship, space_station);

    // space_station.collide(space_ship);
    // space_station.collide(asteroid);

    // asteroid.collide(space_ship);
    // asteroid.collide(space_station);
}
