#ifndef TY_STRING_H_
#define TY_STRING_H_

#include "../../../common/common.h"
#include "ty_string_value.h"
#include "ty_rciptr.h"

class CTYString
{
public:
    CTYString(const char*);

private:
    // smart pointer of CTYStringValue
    CTYRCIPtr<>
};

#endif