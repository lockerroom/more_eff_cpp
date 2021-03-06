#ifndef CRCIPTR_H_
#define CRCIPTR_H_

#include "../../../common/common.h"
#include "count_holder.h"

template <typename T>
class CRCIPtr
{
public:
    CRCIPtr(T*);
    CRCIPtr(const CRCIPtr&);
    ~CRCIPtr();
    CRCIPtr& operator=(const CRCIPtr&);

    bool is_shared() const;
    void delete_reference();
    void make_unshareable();

    const T* operator->() const;
    T* operator->();
    const T& operator*() const;
    T& operator*();

private:
    void init();
    void lazy_copy();

private:
    CCountHolder<T>* m_value;
};

template <typename T>
CRCIPtr<T>::CRCIPtr(T* real_ptr)
: m_value(new CCountHolder<T>(real_ptr))
{
    init();
}

template <typename T>
CRCIPtr<T>::CRCIPtr(const CRCIPtr& rhs)
{
    m_value = rhs.m_value;
    init();
}

template <typename T>
CRCIPtr<T>::~CRCIPtr()
{
    m_value->delete_reference();
}

template <typename T>
CRCIPtr<T>& CRCIPtr<T>::operator=(const CRCIPtr& rhs)
{
    m_value->delete_reference();
    m_value = rhs.m_value;
    init();
    return *this;
}

template <typename T>
bool CRCIPtr<T>::is_shared() const
{
    return m_value->is_shared();
}

template <typename T>
void CRCIPtr<T>::delete_reference()
{
    m_value->delete_reference();
}

template <typename T>
void CRCIPtr<T>::make_unshareable()
{
    m_value->make_unshareable();
}

template <typename T>
const T* CRCIPtr<T>::operator->() const
{
    return m_value->get_holder();
}

template <typename T>
T* CRCIPtr<T>::operator->()
{
    std::cout << "non-const operator ->" << std::endl;
    lazy_copy();
    return m_value->get_holder();
}

template <typename T>
const T& CRCIPtr<T>::operator*() const
{
    return *(m_value->get_holder());
}

template <typename T>
T& CRCIPtr<T>::operator*()
{
    // std::cout << "operator *" << std::endl;
    lazy_copy();
    return *(m_value->get_holder());
}

template <typename T>
void CRCIPtr<T>::init()
{
    if (!(m_value->is_shareable()))
    {
        m_value = new CCountHolder<T>(*m_value);
    }

    m_value->add_reference();
}

template <typename T>
void CRCIPtr<T>::lazy_copy()
{
    // std::cout << "Debug : lazy_copy" << std::endl;
    if (m_value->is_shared())
    {
        m_value->delete_reference();
        m_value = new CCountHolder<T>(m_value->get_holder());
        m_value->add_reference();
    }
}

#endif
