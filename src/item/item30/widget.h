// class like CStringValue
#ifndef WIDGET_H_
#define WIDGET_H_

#include "../../common/common.h"

class CWidget
{
public:
    CWidget(int);
    CWidget(const CWidget&);
    ~CWidget();
    CWidget& operator=(const CWidget&);
    
    void doThis();
    int showWhat() const;

private:
    int m_size;
};

#endif
