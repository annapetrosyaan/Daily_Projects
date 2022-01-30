#ifndef __SMARTPOINTER__
#define __SMARTPOINTER__

template <class T>
class RM
{
public:
   RM();
   ~RM();
   RM(T*);
   RM(RM&&) noexcept;
   RM& operator=(RM&&) noexcept;
//delete copy and assignment
   RM(const RM&)=delete;
   RM& operator=(const RM&)=delete;

public:
   //operators
   T& operator*();
   T* operator->()const;
public:
   const T* get()const;
   void reset()noexcept;

private:
  T* ptr;

};

#include "SmartPointer.hpp"

#endif //!__SMARTPOINTER__