#include "cstringvalue.h"

#include <cstring>

CStringValue::CStringValue(const char* real_ptr)
: m_data(nullptr)
{
    copy_a_string(real_ptr);
}

CStringValue::CStringValue(const CStringValue& rhs)
: m_data(nullptr)
{
    copy_a_string(rhs.m_data);
}

CStringValue::~CStringValue()
{
    delete_local_string();
}

CStringValue& CStringValue::operator=(const CStringValue& rhs)
{
    delete_local_string();
    copy_a_string(rhs.m_data);
    return *this;
}

const char* CStringValue::get_data() const
{
    return m_data;
}

char* CStringValue::get_data()
{
    return m_data;
}

void CStringValue::copy_a_string(const char* real_ptr)
{
    m_data = new char[strlen(real_ptr) + 1];
    strcpy(m_data, real_ptr);
}

void CStringValue::delete_local_string()
{
    if (m_data)
    {
        delete [] m_data;
        m_data = nullptr;
    }
}
