#ifndef TY_RCOBJECT_H_
#define TY_RCOBJECT_H_

#include "../../../common/common.h"

class CTYRCObject
{
protected:
    CTYRCObject();
    CTYRCObject(const CTYRCObject&);
    virtual ~CTYRCObject();
    CTYRCObject& operator=(const CTYRCObject&);

    void make_unshareable();
    bool is_shareable() const;
    bool is_shared() const;

public:
    void add_reference();
    void remove_reference();

private:
    int m_ref_count;
    bool m_shareable;
};

CTYRCObject::CTYRCObject()
: m_ref_count(0)
, m_shareable(true)
{

}

CTYRCObject::CTYRCObject(const CTYRCObject& rhs)
: m_ref_count(0)
, m_shareable(true)
{

}

CTYRCObject::~CTYRCObject()
{

}

CTYRCObject& CTYRCIPtr::operator=(const CTYRCObject& rhs)
{
    return *this;
}

void CTYRCObject::make_unshareable()
{
    m_shareable = false;
}

bool CTYRCObject::is_shareable() const
{
    return m_shareable;
}

bool CTYRCObject::is_shared() const
{
    return (m_ref_count > 1);
}

void CTYRCObject::add_reference()
{
    ++ m_ref_count;
}

void CTYRCObject::remove_reference()
{
    if (--m_ref_count == 0)
        return this;
}

#endif
