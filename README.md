# ft_containers

Task: Implement the vector and map containers using the structure of the respective STL containers as reference. As with all C++ 42 projects, only the C++98 standard may be used.
NEXT UP: (1) write at function to see if fill constructor has worked, check for memory leaks; (2) do range constructor

A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates.
A 'class template' allows you to define a generic class that can work with different data types. 
A vector is a dynamic array, and it should be able to take all kinds of variables (string, int, long long, etc.)

Vector::
A vector is a dynamic array.

Tip from Andrei (mat10243x) : work out what functions need to be included. To see what the header you have to build actually looks like, 
$ cd /usr/include/c++/11/bits
$ code .
^^this brings ups all the standard c++ headers
The functions included in C++98 can be deduced from cplusplus.com and cppreference.com
Tip from Ulli: just start with the constructor and destructor




std::allocator