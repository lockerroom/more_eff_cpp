#ifndef TY_STRING_VALUE_H_
#define TY_STRING_VALUE_H_

#include "../../../common/common.h"

class CTYStringValue
{
public:
    CTYStringValue(const char*);
    CTYStringValue(const CTYStringValue&);
    ~CTYStringValue();
    CTYStringValue& operator=(const CTYStringValue&);
    const char& operator[](int) const;
    char& operator[](int);

private:
    void make_a_copy(const char*);
    void delete_local();

private:
    char* m_data;
};

#endif