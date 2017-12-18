#ifndef MY_STRING_H_
#define MY_STRING_H_

#include "../../common/common.h"

struct StringValue
{
    int ref_count;
    char* data;
    StringValue(const char* initValue);
    ~StringValue();
};

class CMyString
{
public:
    CMyString(const char* value = "");
    CMyString(const CMyString&);
    CMyString& operator=(const CMyString&);

    void write_data_address() const;

private:
    void copy_a_string(const char*);
    void delete_a_string();

private:
    char* data;
};


#endif
