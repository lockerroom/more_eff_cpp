#ifndef COLLISION_PROCESS_H_
#define COLLISION_PROCESS_H_

#include "asteroid.h"
#include "space_ship.h"
#include "space_station.h"
#include "unknown_collision.h"
#include "collision_map.h"

namespace
{
    void ship_ship(const CGameObject& space_ship_1, const CGameObject& space_ship_2)
    {
        std::cout << "One space ship collide with another space ship." << std::endl;
    }

    void station_station(const CGameObject& space_station_1, const CGameObject& space_station_2)
    {
        std::cout << "One space station collide with another space station." << std::endl;
    }

    void asteroid_asteroid(const CGameObject& asteroid_1, const CGameObject& asteroid_2)
    {
        std::cout << "One asteroid collide with another asteroid." << std::endl;
    }

    void ship_asteroid(const CGameObject& space_ship, const CGameObject& asteroid)
    {
        std::cout << "One space ship collide with a asteroid." << std::endl;
    }

    void ship_station(const CGameObject& space_ship, const CGameObject& space_station)
    {
        std::cout << "One space ship collide with a space station" << std::endl;
    }

    void asteroid_station(const CGameObject& asteroid, const CGameObject& space_station)
    {
        std::cout << "One asteroid collide with a space station" << std::endl;
    }

    void asteroid_ship(const CGameObject& asteroid, const CGameObject& space_ship)
    {
        ship_asteroid(space_ship, asteroid);
    }

    void station_ship(const CGameObject& space_station, const CGameObject& space_ship)
    {
        ship_station(space_ship, space_station);
    }

    void station_asteroid(const CGameObject& space_station, const CGameObject& asteroid)
    {
        asteroid_station(asteroid, space_station);
    }
}

void init_collision_map()
{
    CCollisionMap::instance().add_entry(typeid(CSpaceShip).name(),
                                        typeid(CSpaceStation).name(),
                                        &ship_station
                                        );
    CCollisionMap::instance().add_entry(typeid(CSpaceShip).name(),
                                        typeid(CAsteroid).name(),
                                        &ship_asteroid
                                        );
    CCollisionMap::instance().add_entry(typeid(CSpaceStation).name(),
                                        typeid(CAsteroid).name(),
                                        &station_asteroid
                                        );
}

void process_collision(const CGameObject& obj1, const CGameObject& obj2)
{
    CCollisionMap::HitFunctionPtr phf = CCollisionMap::instance().lookup(obj1, obj2);

    if (phf)
    {
        phf(obj1, obj2);
    }
    else
    {
        throw CUnknownCollision(obj1, obj2); 
    }
}

#endif
