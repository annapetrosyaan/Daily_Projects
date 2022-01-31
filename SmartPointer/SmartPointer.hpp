#include <iostream>

template <typename T>
RM<T>::RM()
{
    ptr = nullptr;
}

template <typename T>
RM<T>::RM(T* source)
{
    ptr = source;
}

template <typename T>
RM<T>::RM(RM&& rhs) noexcept
{
    ptr = rhs.ptr;
    rhs.ptr = nullptr;
}

template <typename T>
RM<T>& RM<T>::operator=(RM&& rhs) noexcept
{
    delete ptr;
    ptr = rhs.ptr;
    rhs.ptr = nullptr;
    return *this;
}

template <typename T>
RM<T>::~RM()
{
    delete ptr;
    ptr = nullptr;
}

template <typename T>
T& RM<T>::operator*()
{
    return *ptr;
}

template <typename T>
T* RM<T>::operator->() const
{ 
    return ptr;
}

template <typename T>
const T* RM<T>::get() const
{
    return ptr;
}

template <typename T>
void RM<T>::reset() noexcept
{
    delete ptr;
    ptr=nullptr;
}
