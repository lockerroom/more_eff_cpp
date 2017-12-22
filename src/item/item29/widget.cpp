#include "widget.h"

CWidget::CWidget(int size)
: m_size(size)
{

}

CWidget::CWidget(const CWidget& rhs)
: m_size(rhs.m_size)
{

}

CWidget::~CWidget()
{

}

CWidget& CWidget::operator=(const CWidget& rhs)
{
    m_size = rhs.m_size;
}

void CWidget::doThis()
{
    std::cout << "CWidget doThis" << std::endl;
}

int CWidget::showWhat() const
{
    return m_size;
}

