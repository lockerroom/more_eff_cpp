#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include "../../commom/common.h"

template <typename T>
class CArray2D
{
public:
    CArray2D(int dim1, int dim2);

    const CArray1D<T>& operator[](int index) const;
    CArray1D<T>& operator[](int index);

private:
    CArray1D<T>* m_data;
    int m_size;
};

#endif
