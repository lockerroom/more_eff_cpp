#ifndef ARRSY_1D_H_
#define ARRSY_1D_H_

#include "../../common/common.h"

template <typename T>
class CArray1D
{
public:
    CArray1D(int);
    CArray1D(const CArray1D&);
    ~CArray1D();
    CArray1D& operator=(const CArray1D&);

    const T& operator[](int index) const;
    T& operator[](int index);

private:
    void create_local_data(const T*, int);
    void delete_local_data();
    void replace_local_data(const T*, int);

private:
    T* m_value;
    int m_size;
};

#endif
