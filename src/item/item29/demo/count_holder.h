#ifndef COUNT_HOLDER_H_
#define COUNT_HOLDER_H_

#include "../../../common/common.h"
#include "crcobject.h"

template <typename T>
class CCountHolder : public CRCObject
{
public:
    CCountHolder(const T*);
    CCountHolder(const CCountHolder&);
    CCountHolder& operator=(const CCountHolder&);
    ~CCountHolder();
    
    const T* get_holder() const;
    T* get_holder();

private:
    T* m_holder;
};

template <typename T>
CCountHolder<T>::CCountHolder(const T* real_ptr)
: m_holder(new T(*real_ptr))
{

}

template <typename T>
CCountHolder<T>::CCountHolder(const CCountHolder& rhs)
: m_holder(new T(*(rhs.get_holder())))
{

}

template <typename T>
CCountHolder<T>& CCountHolder<T>::operator=(const CCountHolder& rhs)
{
    if (m_holder)
    {
        delete m_holder;
        m_holder = nullptr;
    }

    m_holder = new T(*(rhs.get_holder));
}

template <typename T>
CCountHolder<T>::~CCountHolder()
{
    if (m_holder)
    {
        delete m_holder;
        m_holder = nullptr;
    }
}

template <typename T>
const T* CCountHolder<T>::get_holder() const
{
    return m_holder;
}

template <typename T>
T* CCountHolder<T>::get_holder()
{
    return m_holder;
}

#endif
