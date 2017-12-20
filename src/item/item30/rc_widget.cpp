#include "rc_widget.h"

CRCWidget::CRCWidget(int size)
: value(new CWidget(size))
{

}

void CRCWidget::doThis()
{
    value->doThis();
}

int CRCWidget::showWhat() const
{
    return value->showWhat();
}
