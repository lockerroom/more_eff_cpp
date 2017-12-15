#ifndef PHONE_NUMBER_H_
#define PHONE_NUMBER_H_

#include "../../common/common.h"

class CPhoneNumber
{
public:
    CPhoneNumber(const std::string& phoneNumber)
    : m_phone_number(phoneNumber)
    {

    }

private:
    std::string m_phone_number;
};

#endif