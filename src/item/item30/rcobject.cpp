#include "rcobject.h"

CRCObject::CRCObject()
: m_ref_count(0)
, m_shareable(true)
{

}

CRCObject::CRCObject(const CRCObject& rhs)
: m_ref_count(0)
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

void CRCObject::addReference()
{
    ++m_ref_count;
}

void CRCObject::removeReference()
{
    if (--m_ref_count == 0)
        delete this;
}

void CRCObject::makeUnshareable()
{
    m_shareable = false;
}

bool CRCObject::isShareable() const
{
    return m_shareable;
}

bool CRCObject::isShared() const
{
    return (m_ref_count > 1);
}
