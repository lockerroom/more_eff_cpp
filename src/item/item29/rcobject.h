#ifndef RC_OBJECT_H_
#define RC_OBJECT_H_

#include "../../common/common.h"

class CRCObject
{
protected:
    CRCObject();
    CRCObject(const CRCObject&);
    virtual ~CRCObject() = 0;

    CRCObject& operator=(const CRCObject&);

public:
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