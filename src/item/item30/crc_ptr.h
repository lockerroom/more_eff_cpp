#ifndef CRC_PTR_H_
#define CRC_PTR_H_

#include "../../common/common.h"

template <typename T>
class CRCPtr
{
public:
    CRCPtr(T* realPtr);
    CRCPtr(const CRCPtr& rhs);
    ~CRCPtr();

    CRCPtr& operator=(const CRCPtr& rhs);

    T* operator->() const;
    T& operator*() const;

private:
    T* pointee;
    void init();
};

template <typename T>
CRCPtr<T>::CRCPtr(T* realPtr)
: pointee(realPtr)
{
    init();
}

template <typename T>
CRCPtr<T>::CRCPtr(const CRCPtr& rhs)
: pointee(rhs.pointee)
{
    init();
}

template <typename T>
CRCPtr<T>::~CRCPtr()
{
    pointee->removeReference();
    pointee = nullptr;
}

template <typename T>
CRCPtr<T>& CRCPtr<T>::operator=(const CRCPtr& rhs)
{
    if (rhs.pointee == this->pointee)
    {
        return *this;
    }

    pointee->removeReference();
    pointee = rhs.pointee;
    init();
    
    return *this;
}

template <typename T>
T* CRCPtr<T>::operator->() const
{
    return pointee;
}

template <typename T>
T& CRCPtr<T>::operator*() const
{
    return *pointee;
}

template <typename T>
void CRCPtr<T>::init()
{
    if (0 == pointee)
        return;

    if (!pointee->isShareable())
    {
        pointee = new T(*pointee);
    }

    pointee->addReference();
}

#endif