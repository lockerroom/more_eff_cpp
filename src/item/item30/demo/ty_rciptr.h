#ifndef TY_RCIPTR_H_
#define TY_RCIPTR_H_

#include "../../../common/common.h"
#include "count_holder.h"

template <typename T>
class CTYRCIPtr
{
public:
    CTYRCIPtr(const T*);
    CTYRCIPtr(const CTYRCIPtr&);
    ~CTYRCIPtr();
    CTYRCIPtr& operator=(const CTYRCIPtr&);

    const T* operator->() const;
    T* operator->();
    const T& operator*() const;
    T& operator*();
    // how to add operator []

private:
    void init();
    void lazy_copy();

private:
    CCountHolder<T> m_holder;
};

template <typename T>
CTYRCIPtr<T>::CTYRCIPtr(const T* realPtr)
: m_holder(new CCountHolder(realPtr))
{
    init();
}

template <typename T>
CTYRCIPtr<T>::CTYRCIPtr(const CTYRCIPtr& rhs)
{
    m_holder = rhs.get_value();
    init();    
}

template <typename T>
CTYRCIPtr<T>::~CTYRCIPtr()
{
    m_holder.remove_reference();
}

template <typename T>
CTYRCIPtr<T>& CTYRCIPtr<T>::operator=(const CTYRCIPtr& rhs)
{
    m_holder.remove_reference();
    m_holder = rhs.m_holder;
    init();
    return *this;
}

template <typename T>
const T* CTYRCIPtr<T>::operator->() const
{
    return m_holder.get_value();
}

template <typename T>
T* CTYRCIPtr<T>::operator->()
{
    lazy_copy();
    return m_holder.get_value();
}

template <typename T>
const T& CTYRCIPtr<T>::operator*() const
{
    return *(m_holder.get_value());
}

template <typename T>
T& CTYRCIPtr<T>::operator*()
{
    lazy_copy();
    return *(m_holder.get_value());
}

template <typename T>
void CTYRCIPtr<T>::init()
{
    if (!m_holder->is_shareable())
    {
        T* old_ptr = m_holder->get_value();
        m_holder = new CCountHolder(new T(*old_ptr));
    }
    m_holder->add_reference();
}

template <typename T>
void CTYRCIPtr<T>::lazy_copy()
{
    if (m_holder->is_shared())
    {
        T* old_ptr = m_holder->get_value();
        m_holder->remove_reference();
        m_holder = new CCountHolder(new T(*old_ptr));
        m_holder->add_reference();
    }
}

#endif
