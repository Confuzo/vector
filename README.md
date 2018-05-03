# Introduction #

This project implements `sc::vector`, a `std::vector` custom implementation.

The project was implemeted in a Programming class at federal University of Rio Grande do Norte.

# Supported Operations #

The array data structure supports insertion at any location, and recovery of information also at any location. All operations are described below.

# Commom operations #

- `size_type size() const` : return the number of elements in the container.
- `void clear()` : remove (either logically or physically) all elements from the container.
- `bool empty()` : returns true if the container contains no elements, and false otherwise.
- `void push_front( const T & value )` : adds value to the front of the list.
- `void push_back( const T & value )` : adds value to the end of the list.
- `void pop_back()` : removes the object at the end of the list.
- `void pop_front()` : removes the object at the front of the list.
- `const T & back() const` : returns the object at the end of the list.
- `const T & front() const` : returns the object at the beginning of the list.
- `void assign( const T & value )` : replaces the content of the list with copies of value `value` .

# Operations exclusive to dynamic array implementation #

- `T & operator[]( size_type pos)` : returns the object at the index pos in the array, with no bounds-checking.
- `T & at ( size_type pos )` : returns the object at the index pos in the array, with bounds-checking. If pos is not within the range of the list, an exception of type
`std::out_of_range` is thrown.
- `size_type capacity() const` : return the internal storage capacity of the array.
- `void reserve( size_type new_cap )` : increase the storage capacity of the array to
a value that’s is greater or equal to `new_cap` . If `new_cap` is greater than the current
`capacity()` , new storage is allocated, otherwise the method does nothing. If new_cap
is greater than the current capacity, all iterators and references, including the past-the-end
`iterator/index`, are invalidated. Otherwise, no iterators or references are invalidated. This
function also preserve the data elements already stored in the list, as well as their original
order.
- `shrink_to_fit()` : Requests the removal of unused capacity. It is a non-binding request
to reduce capacity() to size() .

# Operator overloading #

- `bool operator==( const vector& lhs, const vector& rhs )` : Checks if
the contents of lhs and rhs are equal, that is, whether `lhs.size() == rhs.size()`
and each element in lhs compares equal with the element in `rhs` at the same position.
- `bool operator!=( const vector& lhs, const vector& rhs)` : Similar to the
previous operator, but the opposite result.

# Getting Iterator #

- `iterator begin()` : returns an `iterator` pointing to the first item in the list.
- `const_iterator cbegin() const` : returns a `constant iterator` pointing to the first
item in the list.
- `iterator end()` : returns an `iterator` pointing to the end mark in the list, i.e. the position
just after the last element of the list.
- `const_iterator cend() const` : returns a `constant iterator` pointing to the end mark
in the list, i.e. the position just after the last element of the list.

# Iterator operations #
- `operator++()` : advances `iterator` to the next location within the list. We should provide
both prefix and posfix form, or `++it` and `it++` .
- `operator*()` as in `*it` : return a reference to the object located at the position pointed
by the `iterator`.
- `operator==()` as in it1 == it2 : returns true if both `iterators` refer to the same
location within the list, and false otherwise.
- `operator!=()` as in it1 != it2 : returns true if both `iterators` refer to a different
location within the list, and false otherwise.

# List container operations that require iterators #
- `iterator insert( iterator pos, const T & value )` : adds value into the
list before the position given by the `iterator pos` . The method returns an `iterator` to the
position of the inserted item.
- `template < typename InItr>
iterator insert( iterator pos, InItr first, InItr last )` : inserts ele-
ments from the range `[first; last)` before `pos` .
- `iterator insert( const_iterator pos, std::initializer_list<T> ilist )` :
inserts elements from the `initializer list ilist` before `pos`` . Initializer list supports the user
of insert as in `myList.insert( pos, {'a', 'b', 'c', 'd'} )` , which would insert the ele-
ments a, b, c, and d in the list before `pos` , assuming that `myList` is a list of `char` .
- `iterator erase( iterator pos )` : removes the object at position `pos` . The
method returns an `iterator` to the element that follows pos before the call.
- `iterator erase( iterator first, iterator last )` : removes elements in the
range `[first; last)` . The entire list may be erased by calling `a.erase(a.begin(), a.end());`
- `void assign( size_type count, const T& value )` : Replaces the contents
with `count` copies of value `value` .
-` template < typename InItr>
void assign( InItr first, InItr last )` : replaces the contents of the list with
copies of the elements in the range `[first; last)` .
- ` void assign( std::initializer_list<T> ilist )` : replaces the contents of
the list with the elements from the `initializer list ilist` .
We may call, for instance, `myList.assign( {'a', 'b', 'c', 'd'} )` , to replace the elements
of the list with the elements a, b, c, and d, assuming that `myList` is a list of `char` .

# How to run #

If you using a linux based system, only type `make` at your project folder to generate the executable file.

The code was organized in several folders, such as:
- src (for .cpp files),
- include (for header
files .h, and .inl), and
- bin (for .o and executable files)


# Usage #

A simple example is demonstred below.

For more details access [online reference](http://en.cppreference.com/w/cpp/container/vector)

```cpp
#include "../include/vector.h"
int main(){
	sc::vector<char> a = {'c', 's','a','b'};

	sc::vector<char>::iterator it = a.begin();

	a.insert(it, {'u','l'});

	std::cout << a.capacity() << std::endl;
	std::cout << "----------------------\n";

	for(; it!=a.end(); it++){
			std::cout << *it << "\n";
	}

	return 0;
}
```

# Authorship

Program developed by Abraão Dantas(<abraaovld@gmail.com>) and Geraldo Júnior(<geraldojrcg@gmail.com>)

&copy; IMD/UFRN 2018-2019.
