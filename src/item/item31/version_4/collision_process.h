#ifndef COLLISION_PROCESS_H_
#define COLLISION_PROCESS_H_

#include "asteroid.h"
#include "space_ship.h"
#include "space_station.h"
#include "unknown_collision.h"

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

    typedef void (*HitFunctionPtr)(const CGameObject&, const CGameObject&);
    typedef std::map<std::pair<std::string, std::string>, HitFunctionPtr> HitMap;

    std::pair<std::string, std::string> make_string_pair(const char* str1, const char* str2)
    {
        return std::pair<std::string, std::string>(str1, str2);
    }
    
    HitMap* InitializeHitMap()
    {
        HitMap* mmp = new HitMap();
        std::pair<std::string, std::string> key1 = make_string_pair(typeid(CSpaceShip).name(), typeid(CSpaceStation).name());
        (*mmp)[key1] = &ship_station;
        key1 = make_string_pair(typeid(CSpaceShip).name(), typeid(CAsteroid).name());
        (*mmp)[key1] = &ship_asteroid;
        key1 = make_string_pair(typeid(CSpaceShip).name(), typeid(CSpaceShip).name());
        (*mmp)[key1] = &ship_ship;

        key1 = make_string_pair(typeid(CSpaceStation).name(), typeid(CSpaceShip).name());
        (*mmp)[key1] = &station_ship;
        key1 = make_string_pair(typeid(CSpaceStation).name(), typeid(CAsteroid).name());
        (*mmp)[key1] = &station_asteroid;
        key1 = make_string_pair(typeid(CSpaceStation).name(), typeid(CSpaceStation).name());
        (*mmp)[key1] = &station_station;

        key1 = make_string_pair(typeid(CAsteroid).name(), typeid(CSpaceShip).name());
        (*mmp)[key1] = &asteroid_ship;
        key1 = make_string_pair(typeid(CAsteroid).name(), typeid(CSpaceStation).name());
        (*mmp)[key1] = &asteroid_station;
        key1 = make_string_pair(typeid(CAsteroid).name(), typeid(CAsteroid).name());
        (*mmp)[key1] = &asteroid_asteroid;

        return mmp;
    }

    HitFunctionPtr lookup(const CGameObject& obj1, const CGameObject& obj2)
    {
        if (&obj1 == &obj2)
            return 0;
        
        HitMap* tmpMap = InitializeHitMap();
        if (!tmpMap)
            return 0;

        std::pair<std::string, std::string> key = make_string_pair(typeid(obj1).name(), typeid(obj2).name());

        HitMap::const_iterator cit = (*tmpMap).find(key);
        if (cit != (*tmpMap).cend())
        {
            delete tmpMap;
            tmpMap = nullptr;
            return (*cit).second;
        }
        else
        {
            delete tmpMap;
            tmpMap = nullptr;
            return 0;
        }
    }
}

void process_collision(const CGameObject& obj1, const CGameObject& obj2)
{
    std::cout << "Debug begin" << std::endl;
        std::cout << typeid(obj1).name() << std::endl;
        std::cout << typeid(obj2).name() << std::endl;
    HitFunctionPtr phf = lookup(obj1, obj2);

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
