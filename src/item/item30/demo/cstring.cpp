#include "cstring.h"

CString::CString(const char* real_ptr)
: m_value(new CStringValue(real_ptr))
{

}

const char& CString::operator[](int index) const
{
    return ((m_value->get_data())[index]);
}

char& CString::operator[](int index)
{
    if (m_value->is_shared())
    {
        m_value->delete_reference();
        m_value = new CStringValue(m_value->get_data());
    }

    m_value->make_unshareable();
    return ((m_value->get_data())[index]);
}

void CString::write_local_pointer()
{
    void* addr_local_data = static_cast<void*>(m_value->get_data());
    std::cout << "Local object's data's address is " << addr_local_data
                  << std::endl
                  << "Local object's data's content is " << *(m_value->get_data())
                  << std::endl;
}