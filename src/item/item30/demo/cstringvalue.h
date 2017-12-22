#ifndef CSTRINGVALUE_H_
#define CSTRINGVALUE_H_

#include "../../../common/common.h"
#include "crcobject.h"

class CStringValue
{
public:
    CStringValue(const char*);
    CStringValue(const CStringValue&);
    ~CStringValue();
    CStringValue& operator=(const CStringValue&);

    const char* get_data() const;
    char* get_data();

private:
    void copy_a_string(const char*);
    void delete_local_string();

private:
    char* m_data;
};

#endif
