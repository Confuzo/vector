#include "vector.h"
//ITERATOR
        template< typename T >
        vector<T>::iterator::iterator(vector<T>::iterator::pointer ptr){
            this->m_ptr = ptr;
        }
        //destructor
        template< typename T >
        vector<T>::iterator::~iterator() = default;
        //copy constructor
        template< typename T >
        vector<T>::iterator::iterator(const typename vector<T>::iterator::iterator& itr){
                this->m_ptr = itr.m_ptr;
        }
        /// Assign operator
        template< typename T >
        typename vector<T>::iterator & vector<T>::iterator::operator=(const iterator& rhs){
                this->m_ptr = rhs.m_ptr;
        }

        template< typename T >
        typename vector<T>::iterator::reference vector<T>::iterator::operator*(void) const{
                return *this->m_ptr;
        }
        // +
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator+(int value){
                return vector<T>::iterator(this->m_ptr + value);
        }
        // -
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator-(int value){
                return vector<T>::iterator(this->m_ptr - value);
        }
        //difference between iterators
        template< typename T >
        typename vector<T>::iterator::difference_type vector<T>::iterator::operator-(const iterator & rhs) const{
                return vector<T>::iterator::difference_type(this->m_ptr - rhs.m_ptr);
        }
        // ++it
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator++(){
                ++this->m_ptr;
                return *this;
        }
        // it++
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator++(int){
                auto temp(*this);
                 ++m_ptr;
                return temp;
        }
        // --it
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator--(){
                --m_ptr;
                return *m_ptr;
        }
        // it--
        template< typename T >
        typename vector<T>::iterator vector<T>::iterator::operator--(int){
                auto temp(*this);
                --m_ptr;
                return temp;
        }

        template< typename T >
        bool vector<T>::iterator::operator==(const iterator& rhs) const{
        return m_ptr == rhs.m_ptr;
        }
        template< typename T >
        bool vector<T>::iterator::operator!=(const iterator& rhs) const{
        return m_ptr != rhs.m_ptr;
        }

//CONST ITERATOR
        template< typename T >
        vector<T>::const_iterator::const_iterator(vector<T>::const_iterator::pointer ptr){
            m_ptr = ptr;
        }
        //destructor
        template< typename T >
        vector<T>::const_iterator::~const_iterator() = default;
        //copy constructor
        template< typename T >
        vector<T>::const_iterator::const_iterator(const const_iterator& itr) : m_ptr(itr.m_ptr){
                /*empty*/
        }
        /// Assign operator
        template< typename T >
        typename vector<T>::const_iterator & vector<T>::const_iterator::operator=(const const_iterator& rhs){
                m_ptr = rhs.m_ptr;
        }

        template< typename T >
        typename vector<T>::const_iterator::reference vector<T>::const_iterator::operator *(void) const{
                return *m_ptr;
        }
        // ++it
        template< typename T >
        typename vector<T>::const_iterator vector<T>::const_iterator:: operator++(){
                return ++m_ptr;
        }
        // it++
        template< typename T >
        typename vector<T>::const_iterator vector<T>::const_iterator:: operator++(int){
                auto temp(*this);
                ++m_ptr;
                return temp;
        }
        // --it
        template< typename T >
        typename vector<T>::const_iterator vector<T>::const_iterator:: operator--(){
                return --m_ptr;
        }
        // it--
        template< typename T >
        typename vector<T>::const_iterator vector<T>::const_iterator:: operator--(int){
                auto temp(*this);
                --m_ptr;
                return temp;
        }

        template< typename T >
        bool vector<T>::const_iterator:: operator==(const const_iterator& rhs) const{
        return m_ptr == rhs.m_ptr;
        }
        template< typename T >
        bool vector<T>::const_iterator:: operator!=(const const_iterator& rhs) const{
        return m_ptr != rhs.m_ptr;
        }
//ITERATOR SPECIAL METHODS
    template <typename T>
    typename vector<T>::iterator vector<T>::begin(void){
            return iterator(m_data);
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::end(void){
            return iterator(m_data+ m_size);
    }

    template <typename T>
    typename vector<T>::const_iterator vector<T>::cbegin(void) const{
        return const_iterator(m_data);
    }

    template <typename T>
    typename vector<T>::const_iterator vector<T>::cend(void) const{
        return const_iterator(m_data + m_size);
    }

//VECTOR
//CONSTRUTORES E DESTRUTORES
    /*Parâmetros
        count - o tamanho da lista.
        valor - o valor para inicializar a lista com.
        fist, last - o intervalo para copiar os elementos de.
        other - outra lista a ser usada como fonte para inicializar os elementos da lista com.
        ilist - lista inicializadora para inicializar os elementos da lista com.*/

    //1- Construtor Default que cria uma lista vazia.
    template <typename T>
    vector<T>::vector(void){
        m_data = new T[SIZE];
        m_size = 0;
        m_capacity = SIZE;
    }
    //2- Constrói a lista com instâncias inseridas por padrão de T.
    template <typename T>
    vector<T>::vector(typename vector<T>::size_type count){
        m_data = new T[count];
        m_size = 0;
        m_capacity = count;
    }
    //3- Constrói a lista com o conteúdo do intervalo [first, last].
    template <typename T>
    template< typename InputIt >
    vector<T>::vector( InputIt first, InputIt last ){
        assign(first,last);
    }
    //4- Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
   template <typename T>
    vector<T>::vector(const vector& other ){
        /*m_size = other.m_size;
        std::copy(&other.m_data[0], &other.m_data[m_size], &m_data[0]);*/
        assign(other.begin(), other.end());
    }
    //5- Constrói a lista com o conteúdo da lista inicializadora init.
   template <typename T>
    vector<T>::vector(const std::initializer_list<T> il ){
       /* m_data = new T[il.size()];
        m_data[0]= 1;
        m_data[1]= 2;
        m_data[2]= 3;
        m_size = 3;
        m_capacity = 3;*/
        assign(il.begin(), il.end());
    }
    //6- Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é desalocado.
    //Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos
   template <typename T>
    vector<T>::~vector(void){
        delete [] m_data;
    }

    /*7- Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
    os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
    estado não especificado depois*/
    template <typename T>
    vector<T> & vector<T>::operator=( const vector& other ){
        assign(other.begin(), other.end());
    }
    //8- Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
    template <typename T>
    vector<T> & vector<T>::operator=( std::initializer_list<T> ilist ){
        assign(ilist.begin(), ilist.end());
    }

    template <typename T>
    typename vector<T>::reference vector<T>::operator[](size_type pos){
        if( pos < 0 or pos >= m_size)
                    throw std::out_of_range("[array::[]] Acesso fora dos limites do vetor");
        return m_data[pos];
    }

    template <typename T>
    typename vector<T>::reference vector<T>::at(size_type pos){
            if( pos < 0 or pos >= m_size)
                    throw std::out_of_range("[array::at()] Acesso fora dos limites do vetor");
            return m_data[pos];
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::size(void) const{
            return m_size;
    }

    template <typename T>
    bool vector<T>::empty(void) const{
            return m_size ==0;
    }

    template <typename T>
    void vector<T>::clear() {
        m_size = 0;
        m_capacity = 0;
        delete [] m_data;
    }

    template <typename T>
    void vector<T>::reserve (size_type new_cap) {
        if(new_cap >= capacity()){
            auto aux = m_size;
            value_type new_vector[new_cap];
            std::memmove(new_vector, m_data, m_size*sizeof(T));
            clear();
            m_data = new T[new_cap];
            std::memmove(m_data, new_vector, aux*sizeof(T));
            m_size = aux + 1;
            m_capacity = new_cap;
        }
    }

    template <typename T>
    void vector<T>::push_front(const T & value){
        auto i = m_size + 1;
        reserve(i);
        value_type new_vector[m_size];
        std::memmove(new_vector, m_data, (i - 1)*sizeof(T));
        m_data[0] = value;
        std::memmove(&m_data[1], new_vector, (i -1)*sizeof(T));
    }

    template <typename T>
    void vector<T>::push_back(const T & value){
        auto i = m_size + 1;
        reserve(i);
        m_data[m_size - 1] = value;
    }

    template <typename T>
    void vector<T>::pop_back(){
        if(!empty()){
            m_size--;
        }
    }

    template <typename T>
    void  vector<T>::pop_front(){
        if(!empty()){
            value_type new_vector [m_size];
            std::memmove(new_vector, &m_data[1], (m_size-1) * sizeof(T));
            m_size--;
            std::memmove(m_data, new_vector, m_size * sizeof(T));
        }
    }

    template <typename T>
    const T & vector<T>:: back() const {
        if(m_size <= 0){
            throw std::out_of_range("Empty vector");
        }
        return m_data[m_size-1];
    }

    template <typename T>
    const T & vector<T>::front() const {
        if(m_size <= 0){
            throw std::out_of_range("Empty vector");
        }
        return m_data[0];
    }

    template <typename T>
    bool vector<T>:: operator==(const vector<T>& rhs){
            if(m_size != rhs.m_size)
                    return false;
            return std::equal(&rhs.m_data[0], &rhs.m_data[m_size], &m_data[0]);
    }

    template <typename T>
    bool vector<T>:: operator!=(const vector<T>& rhs){
            if(m_size != rhs.m_size)
                    return true;
            return std::equal(&rhs.m_data[0], &rhs.m_data[m_size], &m_data[0]);
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::capacity( void ) const{
        return m_capacity;
    }

    template <typename T>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator pos, const T& value){
        auto i = m_size + 1;
    
        reserve(i);
        m_data[m_size -1 ] = value;
        auto aux = end();
        //std::cout << *(aux -1) << std::endl; 
        auto index = (aux - pos);
        /*std::cout << index << std::endl;
        value_type new_vector [i - 1];
        std::memmove(new_vector, &m_data[index], (m_size - index)*sizeof(T));
        if(index < m_size){
            m_data[index] = value;
        }
        std::memmove(&m_data[index+1], new_vector, (m_size - index)*sizeof(T));
        std::cout << size() << " " <<  m_size << std::endl;*/
        return pos + 1;
    }

    template <typename T>
     template <typename InItr>
      typename vector<T>::iterator vector<T>::insert( typename vector<T>::iterator pos, InItr first, InItr last){
            size_type i = 0;
			auto ini(first);
			while(ini != last){
				i++;
				ini++;
			}
			auto new_cap = i + m_size;
			reserve(new_cap);
			iterator aux = begin();
			auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);
			value_type new_vector [m_size];
			std::memmove(new_vector, &m_data[index], m_size*sizeof(T));
			while(first != last){
				m_data[index] = *first;
				index++;
				first++;
			}
			std::memmove(&m_data[index], new_vector, m_size*sizeof(T));
            return pos;
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::insert( typename vector<T>::iterator pos, std::initializer_list<T> ilist){
       insert(pos, ilist.begin(), ilist.end());
    }
    template<typename T>
    typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator pos){
                iterator aux = begin();
                auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);
                value_type new_vector [m_size];
                std::memmove(new_vector, &m_data[index+1], m_size*sizeof(T));
                std::memmove(&m_data[index], new_vector, m_size*sizeof(T));
                m_size--;
                return aux;
            }
    template<typename T>
    typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator first, typename vector<T>::iterator last){
        value_type new_vector [m_size];
        auto i = 0;
        auto j = 0;
        while(first != last){
            if(m_data[i] != *first){
                new_vector[j] = m_data[i];
                j++;
            }else{
                m_size--;
            }
            i++;
            first++;
        }
        std::memmove(m_data,new_vector, m_size*sizeof(T));
        return first;
    }
    template<typename T>
    void vector<T>::assign(typename vector<T>::size_type count, const T & value){
        for (size_type i = 0; i< count; i++){
            m_data[i] = value;
        }
        m_capacity = count;
        m_size = count;
    }

    template<typename T>
    template <typename InItr>
	void vector<T>::assign(InItr first, InItr last){
        if(m_size != 0){
            clear();
        }
        auto ini = 0;
        m_capacity = last - first;
        m_data = new T[m_capacity];
        m_size = m_capacity;
        while(first != last){
            m_data[ini] = *first;
            ini++;
            first++;
        }
	}

    template<typename T>
    void vector<T>::assign(std::initializer_list<T> ilist){
       assign(ilist.begin(),ilist.end());
    }
