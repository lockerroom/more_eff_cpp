#include "my_string.h"
#include <cstring>

// ===================== class CStringValue ===============================
CStringValue::CStringValue(const char* initValue)
: ref_count(1)
, data(nullptr)
{
    copy_a_string(initValue);
}

CStringValue::~CStringValue()
{
    delete_a_string();
}

void* CStringValue::data_address()
{
    return static_cast<void*>(data);
}

void CStringValue::copy_a_string(const char* lhs)
{
    int ilen = strlen(lhs);
    data = new char[ilen + 1];
    data = strcpy(data, lhs);
}

void CStringValue::delete_a_string()
{
    if (data)
    {
        delete [] data;
        data = 0;
    }
}
// ===================== class CStringValue ===============================

// ===================== class CMyString ===============================
// Be careful at the initialize list
CMyString::CMyString(const char* value)
: m_string_value(new CStringValue(value))
{
    
}

// Be careful at the initialize list
CMyString::CMyString(const CMyString& rhs)
: m_string_value(nullptr)
{
   m_string_value = rhs.m_string_value;
   ++m_string_value->ref_count; 
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    delete_local_string();
    m_string_value = rhs.m_string_value;
    ++m_string_value->ref_count;

    return *this;
}

CMyString::~CMyString()
{
    delete_local_string();
}

void CMyString::string_value_address () const
{
    if (m_string_value)
    {
        std::cout << "StringValue's data's address is " << m_string_value->data_address() << std::endl;
    }
    else
    {
        std::cout << "StringValue's pointer is null" << std::endl;
    }
}

void CMyString::delete_local_string ()
{
    if (--m_string_value->ref_count == 0)
    {
        delete m_string_value;
        m_string_value = nullptr;
    }
}

// ===================== class CMyString ===============================
