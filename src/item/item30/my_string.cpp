#include "my_string.h"
#include <cstring>

// ===================== class CStringValue ===============================
CStringValue::CStringValue(const char* initValue)
: data(nullptr)
// , ref_count(1)
// , shareable(true)
{
    copy_a_string(initValue);
}

CStringValue::CStringValue(const CStringValue& rhs)
: data(nullptr)
{
    copy_a_string(rhs.data);
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
: m_string_value(rhs.m_string_value)
{

}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    m_string_value = rhs.m_string_value;
    return *this;
}

CMyString::~CMyString()
{
    delete_local_string();
}

const char& CMyString::operator[] (int index) const
{
    return m_string_value->data[index];
}

char& CMyString::operator[] (int index)
{
    if (m_string_value->isShared())
    {
        m_string_value->removeReference();
        m_string_value = new CStringValue(m_string_value->data);
    }

    m_string_value->makeUnshareable();
    return m_string_value->data[index];
}

void CMyString::string_value () const
{
    std::cout << "StringValue's data's address is " << m_string_value->data_address() << " ; "
                  << "StringValue's data is " << m_string_value->data << " ; "
                  // << "StringValue's reference number is " << m_string_value->ref_count 
                  << std::endl;
}

void CMyString::delete_local_string ()
{
    // This function is useless because of useing smart pointer
    // m_string_value->removeReference();
    // m_string_value = nullptr;
}

// ===================== class CMyString ===============================
