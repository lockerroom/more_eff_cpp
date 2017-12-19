#ifndef RC_OBJECT_H_
#define RC_OBJECT_H_

#include "../../common/common.h"

class CRCObject
{
public:
    CRCObject();
    CRCObject(const CRCObject&);
    virtual ~CRCObject() = 0;

    CRCObject& operator=(const CRCObject&);

    void addReference();
    void removeReference();
    void makeUnshareable();
    bool isShareable() const;
    bool isShared() const;

private:
    int m_ref_count;
    int m_shareable;
};

#endif