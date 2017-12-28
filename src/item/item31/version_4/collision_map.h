#ifndef COLLISION_MAP_H_
#define COLLISION_MAP_H_

#include "../../../common/common.h"

class CGameObject;

class CCollisionMap
{
private:
    CCollisionMap();
    CCollisionMap(const CCollisionMap&);

public:
    typedef void (*HitFunctionPtr)(const CGameObject&, const CGameObject&);
    typedef std::pair<std::string, std::string> KeyType;
    typedef std::map<KeyType, HitFunctionPtr> HitMap;

public:
    static CCollisionMap& instance();

    void add_entry(const std::string& type1, const std::string& type2, HitFunctionPtr phf, bool symmetric = true);
    void delete_entry(const std::string& type1, const std::string& type2);
    HitFunctionPtr lookup(const CGameObject&, const CGameObject&) const ;
    
private:
    HitFunctionPtr lookup(const std::string&, const std::string&) const ;

    KeyType make_key(const std::string&, const std::string&);

private:
    static CCollisionMap m_instance;
    HitMap m_hit_map;    
}; 

#endif
