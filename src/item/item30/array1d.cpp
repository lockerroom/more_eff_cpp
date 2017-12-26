#include "array1d.h"

template <typename T>
CArray1D<T>::CArray1D(int dim)
: m_data(nullptr)
, m_size(dim)
{
    m_data = new T[dim];
}

template <typename T>
CArray1D<T>::CArray1D(const CArray1D& rhs)
: m_data(nullptr)
, m_size(0)
{
    create_local_data(rhs.m_data, rhs.m_size);
}

template <typename T>
CArray1D<T>::~CArray1D()
{
    delete_local_data();
}

template <typename T>
CArray1D<T>::operator=(const CArray1D& rhs)
{
    replace_local_data(rhs.m_data, rhs.m_size);
    return *this;
}

template <typename T>
const T& CArray1D<T>::operator[] (int index) const
{
    return m_data[index];
}

template <typename T>
T& CArray1D<T>::operator[] (int index)
{
    return m_data[index];
}

template <typename T>
void CArray1D<T>::create_local_data(const T* src, int size)
{
    if (!src || size <= 0) return;

    m_size = size;
    m_data = new T[m_size];
    for (int i = 0 ; i < m_size ; ++i)
    {
        m_data[i] = src[i];
    }
}

template <typename T>
void CArray1D<T>::delete_local_data()
{
    if (m_data)
    {
        delete [] m_data;
        m_data = nullptr;
    }

    m_size = 0;
}

template <typename T>
void CArray1D<T::replace_local_data(const T* src, int size)
{
    if (m_data)
    {
        delete_local_data();
    }
    create_local_data(src, size);
}
