namespace sc{
    template <typename T>
    class iterator{
        public: //iterator traits
                typedef T*                              pointer;
                typedef std::ptrdiff_t                  diference_type;
                typedef T                               value_type;
                typedef T&                              reference;
                typedef std::bidirectional_iterator_tag iterator_category;
                //constructor (empty and single value)
                iterator(pointer ptr=nullptr) : m_ptr(ptr);
                //destructor
                ~iterator() = default;
                //copy constructor
                iterator(const iterator& itr) : m_ptr(itr.m_ptr);
                /// Assign operator
                iterator& operator=(const iterator& rhs);

                reference operator *(void) const;
                // ++it
                iterator operator++();
                // it++
                iterator operator++(int);
                // --it
                iterator operator--();
                // it--
                iterator operator--(int);

                bool operator==(const iterator& rhs) const;
                bool operator!=(const iterator& rhs) const;
        private:
                pointer m_ptr;

    };
}