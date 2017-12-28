#include "collision_map.h"
#include "asteroid.h"
#include "space_ship.h"
#include "space_station.h"

CCollisionMap::CCollisionMap m_instance;

CCollisionMap::CCollisionMap()
{

}

CCollisionMap::CCollisionMap(const CCollisionMap& rhs)
{

}

CCollisionMap& CCollisionMap::instance()
{
    return m_instance;
}

void CCollisionMap::add_entry(const std::string& type1, const std::string& type2, HitFunctionPtr phf, bool symmetric/* = true */)
{
    KeyType key = make_key(type1, type2);
    m_hit_map.insert(std::make_pair(key, phf));
}

void CCollisionMap::delete_entry(const std::string& type1, const std::string& type2)
{
    KeyType key = make_key(type1, type2);

    HitMap::iterator it = m_hit_map.find(key);
    if (it != m_hit_map.end())
    {
        m_hit_map.erase(it);
    }
}

HitFunctionPtr CCollisionMap::lookup(const CGameObject& obj1, const CGameObject& obj2) const
{
    return lookup(typeid(obj1).name(), typeid(obj2).name());
}

HitFunctionPtr CCollisionMap::lookup(const std::string& obj1_type, const std::string& obj2_type) const
{
    KeyType key1 = make_key(obj1_type, obj2_type);
    KeyType key2 = make_key(obj2_type, obj1_type);

    HitMap::const_iterator cit = m_hit_map.find(key1);
    HitMap::const_iterator cit2 = m_hit_map.find(key2);
    if (cit != m_hit_map.cend())
    {
        return (*cit).second;
    }
    else if (cit2 != m_hit_map.cend())
    {
        return (*cit2).second;
    }
    else
    {
        return 0;
    }
}

KeyType CCollisionMap::make_key(const std::string& str1, const std::string& str2)
{
    return std::make_pair(str1, str2);
}
