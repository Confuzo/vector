namespace sc{
    template <typename T>
    class const_iterator{
        public:
            typedef const T*                              pointer;
            typedef const std::ptrdiff_t                  diference_type;
            typedef const T                               value_type;
            typedef const T&                              reference;
            typedef const std::bidirectional_iterator_tag iterator_category;

            //constructor (empty and single value)
            const_iterator(pointer ptr=nullptr) : m_ptr(ptr);
            //destructor
            ~const_iterator() = default;
            //copy constructor
            const_iterator(const const_iterator& itr) : m_ptr(itr.m_ptr);
            /// Assign operator
            const_iterator& operator=(const const_iterator& rhs);

            reference operator *(void) const;
            // ++it
            const_iterator operator++();
            // it++
            const_iterator operator++(int);
            // --it
            const_iterator operator--();
            // it--
            const_iterator operator--(int);

            bool operator==(const const_iterator& rhs) const;
            bool operator!=(const const_iterator& rhs) const;

        private: pointer m_ptr;

    };
}