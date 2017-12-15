#include "temporary_obj.h"

CTemporaryObj::CTemporaryObj(int content)
: m_content(content)
{
    std::cout << "Construct CTemporaryObj with content" << m_content << std::endl;
}

CTemporaryObj::CTemporaryObj(const CTemporaryObj& obj)
: m_content(obj.m_content)
{
    std::cout << "Copy construct CTemporary with content" << m_content << std::endl;
}

CTemporaryObj::~CTemporaryObj()
{
    std::cout << "Destruct CTemporaryObj with content " << m_content << std::endl;
}

bool CTemporaryObj::IsSame(const CTemporaryObj& obj)
{
    return m_content == obj.m_content;
}

void CTemporaryObj::print()
{
    std::cout << "CTemporaryObj's function print with " << m_content << std::endl;
}

