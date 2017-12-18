#include "my_string.h"
#include <cstring>

// Be careful at the initialize list
CMyString::CMyString(const char* value)
: data(nullptr)
{
    // std::cout << "Debug : constructor" << std::endl;
    copy_a_string(value);
}

// Be careful at the initialize list
CMyString::CMyString(const CMyString& rhs)
: data(nullptr)
{
    // std::cout << "Debug : Delete local string." << std::endl;
    delete_a_string();
    // std::cout << "Debug : copy string from rhs" << std::endl;
    copy_a_string(rhs.data);
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    // std::cout << "Debug : Delete local string." << std::endl;
    delete_a_string();
    // std::cout << "Debug : copy string from rhs" << std::endl;
    copy_a_string(rhs.data);
}

void CMyString::write_data_address () const
{
    std::cout << static_cast<void*>(data) << std::endl;
}

void CMyString::copy_a_string(const char* lhs)
{
    int ilen = strlen(lhs);
    // std::cout << "Debug : copy_a_string len is " << ilen << std::endl;
    data = new char[ilen + 1];
    data = strcpy(data, lhs);
    // std::cout << "Debug : copy_a_string str content is " << data << std::endl;
}

void CMyString::delete_a_string()
{
    if (data)
    {
        // std::cout << "Debug :: Begin delete local string" << std::endl;
        delete [] data;
        // std::cout << "Debug :: End delete local string" << std::endl;
        data = 0;
    }
}
