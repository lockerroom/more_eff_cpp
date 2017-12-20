#include "count_holder.h"

template <typename T>
CCountHolder<T>::CCountHolder(const T* value)
: m_value(value)
{

}

template <typename T>
CCountHolder<T>::~CCountHolder()
{
    delete m_value;
}

template <typename T>
T* CCountHolder<T>::get_value()
{
    return m_value;
}

template <typename T>
void CCountHolder<T>::set_value(const T* value)
{
    m_value = value;
}
