#ifndef RCI_PTR_H_
#define RCI_PTR_H_

#include "../../common/common.h"

template <typename T>
class CRIPtr 
{
public:
    CRIPtr(T* realPtr = 0);
    CRIPtr(const CRIPtr&);
    ~CRIPtr();

    CRIPtr& operator=(const CRIPtr&);
    const T* operator->() const;
    T* operator->() const;
    const T& operator*() const;
    T& operator*();

private:
    struct CountHolder : public CRCObject
    {
        CountHolder()
        : pointee(nullptr)
        {

        }

        ~CountHolder()
        {
            if (pointee)
            {
                delete pointee;
                pointee = nullptr;
            }
        }

        T* pointee;
    }

    CountHolder* m_count_holder;

    void init();
    void make_a_copy();
};

template <typename T>
CRIPtr<T>::CRIPtr(T* realPtr)
: m_count_holder(new CountHolder)
{
    m_count_holder->pointee = realPtr;
    init();
}

template <typename T>
CRIPtr<T>::CRIPtr(const CRIPtr& rhs)
: m_count_holder(nullptr)
{
    m_count_holder = rhs.m_count_holder;
    init();
}

template <typename T>
CRIPtr<T>::~CRIPtr()
{
    m_count_holder->removeReference();
}

template <typename T>
CRIPtr<T>& CRIPtr<T>::operator=(const CRIPtr& rhs)
{
    m_count_holder = rhs.m_count_holder;
    return *this;
}

template <typename T>
const T* CRIPtr<T>::operator->() const
{
    return m_count_holder->pointee;
}

template <typename T>
T* CRIPtr<T>::operatpr->()
{
    return m_count_holder->pointee;
}

template <typename T>
const T& CRIPtr<T>::operator->() const
{
    return *(m_count_holder->pointee);
}

template <typename T>
T& CRIPtr<T>::operatpr->()
{
    return *(m_count_holder->pointee);
}

template <typename T>
void CRIPtr<T>::init()
{
    if (!m_count_holder->isShareable())
    {
        T* oldT = m_count_holder->pointee;
        m_count_holder = new CountHolder();
        m_count_holder->pointee = oldT;
    }

    m_count_holder->addReference();
}

template <typename T>
void CRIPtr<T>::make_a_copy()
{

}

#endif