#include "const_iterator.h"
//constructor (empty and single value)
    template< typename T >
    const_iterator<T>::const_iterator(pointer ptr=nullptr) : m_ptr(ptr){
            /*empty*/
    }
    //destructor
    template< typename T >
    const_iterator<T>::~const_iterator() = default;
    //copy constructor
    template< typename T >
    const_iterator<T>::const_iterator(const const_iterator& itr) : m_ptr(itr.m_ptr){
            /*empty*/
    }
    /// Assign operator
    template< typename T >
    const_iterator& const_iterator<T>::operator=(const const_iterator& rhs){
            m_ptr = rhs.m_ptr;
    }

    template< typename T >
    reference const_iterator<T>::operator *(void) const{
            return *m_ptr;
    }
    // ++it
    template< typename T >
    const_iterator const_iterator<T>:: operator++(){
            return ++m_ptr;
    }
    // it++
    template< typename T >
    const_iterator const_iterator<T>:: operator++(int){
            auto temp(*this);
            ++m_ptr;
            return temp;
    }
    // --it
    template< typename T >
    const_iterator const_iterator<T>:: operator--(){
            return --m_ptr;
    }
    // it--
    template< typename T >
    const_iterator const_iterator<T>:: operator--(int){
            auto temp(*this);
            --m_ptr;
            return temp;
    }

    template< typename T >
    bool const_iterator<T>:: operator==(const const_iterator& rhs) const{
    return m_ptr == rhs.m_ptr;
    }
    template< typename T >
    bool const_iterator<T>:: operator!=(const const_iterator& rhs) const{
    return m_ptr != rhs.m_ptr;
    }