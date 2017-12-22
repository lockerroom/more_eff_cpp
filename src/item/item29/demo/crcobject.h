#ifndef CRCOBJECT_H_
#define CRCOBJECT_H_

#include "../../../common/common.h"

class CRCObject
{
protected:
    CRCObject();
    CRCObject(const CRCObject&);
    virtual ~CRCObject();
    CRCObject& operator=(const CRCObject&);

public:
    void add_reference();
    void delete_reference();
    bool is_shareable() const;
    bool is_shared() const;
    void make_unshareable();

private:
    int m_ref_cnt;
    bool m_shareable;
};

#endif