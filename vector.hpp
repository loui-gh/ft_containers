/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:36:49 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/16 17:23:36 by sammy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory> // required for  std::allocator
/*create the four constructor types found in std::vector
1) Empty or default constructor - construct EMPTY container with no elements
2) Fill constructor - construct a container with n elements, all copies of val
3) Range constructor - construct a container with as many elements as the range (first, last)//how does it work?
4) Copy constructor - constructs a container with a copy of each of the elements in x, same order
**DESTRUCTOR** note: the memory is deallocated here
Note! *printf(), *alloc() and free() are FORBIDDEN 
**You must follow the original naming. Take care of details --so create aliases using typedef** 

*/
namespace   ft {

    template<typename T, class Allocator = std::allocator<T>>
    class Vector {
       
        public: 
            typedef T               value_type;
            typedef Allocator       allocator_type;
            typedef unsigned long   size_type;
            typedef T*              pointer;
        
        private:
            pointer     _first;
            pointer     _last;
            size_type   _capacity;
            size_type   _size;
        
        public:
        /*alloc = allocator object. allocator_type is internal allocator used by container, defined as 
        ALIAS of typename Alloc, which is an alias of std::allocator*/
            explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0){
                std::cout << "Default constructor called\n";
                };//What is happening here?? instantiation of std:;allocator??
        /*n - initila container size; val = value to fill container with, value_type the type of eles in container it's an alias of its first template param*/
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>         vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            vector (const vector& x);

            ~vector( void ) {std::cout << "Destructor called\n"; return;}

    }


};
#endif