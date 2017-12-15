#ifndef TEMPORARY_OBJ_H_
#define TEMPORARY_OBJ_H_

#include "../../common/common.h"

class CTemporaryObj
{
public:
    CTemporaryObj(int);
    CTemporaryObj(const CTemporaryObj&);

    virtual ~CTemporaryObj();

public:
    bool IsSame(const CTemporaryObj&);
    virtual void print();

private:
    int m_content;
};

#endif
