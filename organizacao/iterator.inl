#include "iterator.h"
// ITERATOR
//constructor (empty and single value)
    template< typename T >
    iterator<T>::iterator(pointer ptr=nullptr) : m_ptr(ptr){
            /*empty*/
    }
    //destructor
    template< typename T >
    iterator<T>:: ~iterator() = default;
    //copy constructor
    template< typename T >
    iterator<T>:: iterator(const iterator& itr) : m_ptr(itr.m_ptr){
            /*empty*/
    }
    /// Assign operator
    template< typename T >
    iterator& iterator<T>:: operator=(const iterator& rhs){
            m_ptr = rhs.m_ptr;
    }

    template< typename T >
    reference iterator<T>:: operator *(void) const{
            return *m_ptr;
    }
    // ++it
    template< typename T >
    iterator iterator<T>:: operator++(){
            return ++m_ptr;
    }
    // it++
    template< typename T >
    iterator iterator<T>:: operator++(int){
            ++m_ptr;
            auto temp(*this);
            return temp;
    }
    // --it
    template< typename T >
    iterator iterator<T>:: operator--(){
            return --m_ptr;
    }
    // it--
    template< typename T >
    iterator iterator<T>:: operator--(int){
            auto temp(*this);
            --m_ptr;
            return temp;
    }

    template< typename T >
    bool iterator<T>::operator==(const iterator& rhs) const{
    return m_ptr == rhs.m_ptr;
    }
    template< typename T >
    bool iterator<T>::operator!=(const iterator& rhs) const{
    return m_ptr != rhs.m_ptr;
    }