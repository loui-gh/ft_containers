/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:36:49 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/17 12:06:28 by sammy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr_t.hpp"
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

    template<typename T, class Alloc = std::allocator<T>>
    class Vector {
       
        public: 
            typedef T                               value_type;
            typedef Alloc                           allocator_type;
            typedef allocator_type::reference       reference;
            typedef allocator_type::const_reference const_reference;
            typedef allocator_type::pointer         pointer;
            typedef allocator_type::const_pointer   const_pointer;
            /*iterator*/
            /*const_iterator*/
            /*reverse_iterator*/
            /*const_reverse iterator*/
            /*difference_type*/
            typedef size_t                          size_type;
            typedef ptrdiff_t       				difference_type;


        
        private:
            allocator_type  _allocator;
            pointer         _first;//range to copy elements from || beg of allocated storage
            pointer         _last;//range to copy elements from || one past last element in vecotr
            size_type       _capacity;
            size_type       _count;//size of container. Initial size = n
        
        public:
        /*default constructor
        PARAMS: alloc is an instance of Allocator (std::allocator)/*/
           explicit vector (const allocator_type& alloc = allocator_type()) : 
                _alloc(alloc), _first(my_nullptr), _last(my_nullptr), _capacity(my_nullptr), _count(0) {}
        /*fill constructor
        PARAMS: 
            @1: n = initial container size
            @2: val = value to fill container with first, 
            @3: last = input iterators to initial and final positions in range. range incl element pointed to by first,
            BUT! range does not incl element pointed to by last */
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
            this->_allocator = alloc;
            this->_first = this->_last = this->_capacity = my_nullptr;//need to initialise values!
            this->_count = 0;

            this->_first = _allocator.allocate(n);
            this->_last = _first + n;
            this->_capacity = _first + n;
            for (  this->_count = 0;  this->_count < n;  this->_count++)
                _allocator.construct(_last, val);
            return ;
        }
            template <class InputIterator>         vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            vector (const vector& x);

            ~vector( void ) {std::cout << "Destructor called\n"; return;}

    }


};
#endif