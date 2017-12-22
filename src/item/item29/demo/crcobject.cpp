#include "crcobject.h"

CRCObject::CRCObject()
: m_ref_cnt(0)
, m_shareable(true)
{

}

CRCObject::CRCObject(const CRCObject& rhs)
: m_ref_cnt(0)
, m_shareable(true)
{
    
}

CRCObject::~CRCObject()
{

}

CRCObject& CRCObject::operator=(const CRCObject& rhs)
{
    return *this;
}

void CRCObject::add_reference()
{
    ++m_ref_cnt;
}

void CRCObject::delete_reference()
{
    if (--m_ref_cnt == 0)
        delete this;
}

bool CRCObject::is_shareable() const
{
    return m_shareable;
}

bool CRCObject::is_shared() const
{
    return (m_ref_cnt > 1);
}

void CRCObject::make_unshareable()
{
    m_shareable = false;
}
