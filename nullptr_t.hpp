/*nullptr_t is a null pointer constant that is implicitly convertible to any pointer type,
and is used to indicate a null pointer value. Prior to C++11, the NULL macro was used to 
represent a null pointer, but it was implemented as an integer constant with a value of 0, 
which could cause problems in certain contexts. For example, 
if you tried to pass NULL to a function that expected a pointer to an overloaded function, 
the compiler might interpret it as a null pointer to an object, rather than a null pointer to a function.

To avoid these kinds of problems, C++11 introduced the nullptr keyword, 
which is implemented as a new type, nullptr_t. When you use nullptr to initialize a pointer,
 or to compare against a pointer, the compiler can automatically deduce the type of the pointer,
  based on the context*/


#ifndef NULLPTR_T_HPP
# define NULLPTR_T_HPP
//from: https://stackoverflow.com/questions/46129024/some-questions-about-implementation-of-nullptr-in-effective-c-by-scott-meyers
# include <iostream>
const // It is a const object...
class nullptr_t 
{
  public:
    template<class T>
    inline operator T*() const // convertible to any type of null non-member pointer...
    { return 0; }

    template<class C, class T>
    inline operator T C::*() const   // or any type of null member pointer...
    { return 0; }

  private:
    void operator&() const;  // Can't take address of nullptr

} my_nullptr = {};

#endif