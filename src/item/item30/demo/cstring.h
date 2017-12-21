#ifndef CSTRING_H_
#define CSTRING_H_

#include "../../../common/common.h"
#include "crciptr.h"
#include "cstringvalue.h"

class CString
{
public:
    CString(const char*);

    const char& operator[](int) const;
    char& operator[](int);

    void write_local_pointer();

private:
    CRCIPtr<CStringValue> m_value;
};

#endif
