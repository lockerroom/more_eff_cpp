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

public:
    void add_entry(const std::string& type1, const std::string& type2, HitFunctionPtr phf, bool symmetric = true);
    void delete_entry(const std::string& type1, const std::string& type2);

    HitFunctionPtr lookup(const CGameObject&, const CGameObject&);
    HitFunctionPtr lookup(const std::string&, const std::string&);

    static CCollisionMap& instance();

private:
    static CCollisionMap m_instance;
}; 

#endif
