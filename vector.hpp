/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:36:49 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/17 17:13:07 by sammy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr_t.hpp"
#include <cstddef>
#include <iostream>
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

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
       
        public: 
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            /*iterator*/
            /*const_iterator*/
            /*reverse_iterator*/
            /*const_reverse iterator*/
            /*difference_type*/
            typedef size_t                                      size_type;
            typedef ptrdiff_t       				            difference_type;


        
        private:
            allocator_type  _allocator;
            pointer         _first;//range to copy elements from || beg of allocated storage
            pointer         _last;//range to copy elements from || one past last element in vecotr
            size_type       _end_of_storage; // the end_of_storage_ pointer is used to indicate the end of the allocated storage for the vector
            size_type       _size_cont_alloc;//size of container. Initial size = n
        
        public:
        /*default constructor
        @param alloc is an instance of Allocator (std::allocator)
        *still have to assign value to private variables???*/
           explicit vector (const allocator_type& alloc = allocator_type()) : 
                _allocator(alloc), _first(my_nullptr), _last(my_nullptr), _end_of_storage(my_nullptr), _size_cont_alloc(0) {}
        /*fill constructor --fills whole container of n elements with n copies of val (value)
        PARAMS: 
            @1: n = initial container size
            @2: val = value to fill container with , 
            @3: last = input iterators to initial and final positions in range. range incl element pointed to by first,
            BUT! range does not incl element pointed to by last */
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
                this->_allocator = alloc;
                this->_first = my_nullptr;//need to initialise values!
                this->_last = my_nullptr; 
                this->_size_cont_alloc = n;

                this->_first = _allocator.allocate(n);
                this->_last = _first + n - 1;
                this->_end_of_storage = _first + n;
                for (  this->_count = 0;  this->_count < n;  this->_count++)
                    _allocator.construct(this->_last, val);
                return ;
        }

    /*What does the destructor do? --destroys all container elements, and deallocates all the **storage capacity** 
    allocated by the vector using its allocator. Note, that if the elements are pointers, the pointed-to objects are not destroyed*/
            ~vector( void ) {
                std::cout << "Destructor called\n";
                /*destroy - destroy: This member function is used to destroy an object at a specified location in memory. 
                It takes a single argument, which is a pointer to the object to destroy.*/
                size_type tmp = this->size();					
				for (size_type i = 0; i < tmp; i++) {
					this->_last--;
					this->_allocator.destroy(this->_last);
				}
				this->_count = 0;
                //--could be the clear function ^^ later!!
               
                /*deallocate*/
                this->_allocator.deallocate(this->first, this->_size_cont_alloc);
                return;
            }

            /*returns no. of elements with values in them*/
            size_type   size() {
                return size_type(this->_last - this->first);
            }

    };

}
#endif