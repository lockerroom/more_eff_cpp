#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include "../../common/common.h"

template <typename T>
class SmartPtr
{
public:
    SmartPtr(T* realPtr = 0);
    ~SmartPtr();
    
    T* operator->() const;
    T& operator*() const;

private:
    SmartPtr(const SmartPtr& rhs);
    // make an assignment to a smart ptr
    SmartPtr& operator=(const SmartPtr& rhs);

private:
    T* pointee;
};

SmartPtr::SmartPtr(T* realPtr)
: pointee(realPtr)
{

}

SmartPtr::~SmartPtr()
{
    if (pointee)
    {
        delete pointee;
        pointee = nullptr;
    }
}

T* SmartPtr::operator->() const 
{
    return pointee;
}

T& SmartPtr::operator*() const
{
    return *pointee;
}

SmartPtr::SmartPtr(const SmartPtr& rhs)
: pointee(rhs.pointee)
{

}

SmartPtr& SmartPtr::operator=(const SmartPtr& rhs)
{
    if (pointee)
    {
        delete pointee;
        pointee = nullptr;
    }

    pointee = rhs.pointee;
}

#endif
