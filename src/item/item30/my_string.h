#ifndef MY_STRING_H_
#define MY_STRING_H_

#include "../../common/common.h"

class CStringValue
{
public:
    CStringValue(const char*);
    ~CStringValue();

public:
    void* data_address();

private:
    void copy_a_string(const char*);
    void delete_a_string();

public:
    int ref_count;
    char* data;
};

class CMyString
{
public:
    CMyString(const char* value = "");
    CMyString(const CMyString&);
    CMyString& operator=(const CMyString&);
    ~CMyString();

    const char& operator[](int) const;
    char& operator[](int);

    void string_value() const;

private:
    void delete_local_string();

private:
    CStringValue* m_string_value;
};


#endif
