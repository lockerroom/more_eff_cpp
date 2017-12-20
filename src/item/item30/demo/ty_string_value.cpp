#include "ty_string_value.h"

#include <cstring>
#include <cstdio>

CTYStringValue::CTYStringValue(const char* real_ptr)
: m_data(nullptr)
{
    make_a_copy(real_ptr);
}

CTYStringValue::CTYStringValue(const CTYStringValue& rhs)
: m_data(nullptr)
{
    make_a_copy(rhs.m_data);
}

CTYStringValue::~CTYStringValue()
{
    delete_local();
}

CTYStringValue& CTYStringValue::operator=(const CTYStringValue& rhs)
{
    // delete_local();
    make_a_copy(rhs.m_data);
    return *this;
}

const char& CTYStringValue::operator[](int index) const
{
    return data[index];
}

char& CTYStringValue::operator[](int index)
{
    return data[index];
}

void CTYStringValue::make_a_copy(const char* real_ptr)
{
    if (m_data)
    {
        delete_local();
    }

    m_data = new char[strlen(real_ptr) + 1];
    strcpy(m_data, real_ptr);
}

void CTYStringValue::delete_local()
{
    if (m_data)
    {
        delete [] m_data;
        m_data = nullptr;
    }
}
