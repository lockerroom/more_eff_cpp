#ifndef COUNT_HOLDER_H_
#define COUNT_HOLDER_H_

#include "../../../common/common.h"
#include "ty_rcobject.h"

template <typename T>
class CCountHolder : public CRCObject
{
public:
    CCountHolder(const T*);
    ~CCountHolder();
    
    T* get_value();
    void set_value(const T*);

private:
    T* m_value;
};

#endif