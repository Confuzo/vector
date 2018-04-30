#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>

namespace sc{
	template <typename T, size_t SIZE=0>
	class vector{

		typedef T value_type;
        typedef size_t size_type;
        typedef T* pointer;
        typedef T& reference;

		private:
			/*pointer m_data;
			pointer m_size;
			pointer m_capacity;*/
			size_type m_size; //!< Stores the array size.
      value_type m_data[ SIZE ]; //the storage area
			size_type m_capacity;
			/*
				.reserve()
					0) ver se o tamanho alocado comporta os novos elementos
					1) alocar nova memoria c/ o dobro da original (*temp)
					2) copiar m.data p/ temp
					3) apagar m_data
					4) m_data = temp;
					5) m_size *= 2;
			*/
		public:
			class iterator{
					public: //iterator traits
							typedef T*                              pointer;
							typedef std::ptrdiff_t                  diference_type;
							typedef T                               value_type;
							typedef T&                              reference;
							typedef std::bidirectional_iterator_tag iterator_category;

							//constructor (empty and single value)
							iterator(pointer ptr=nullptr) : m_ptr(ptr){
									/*empty*/
							}
							//destructor
							~iterator() = default;
							//copy constructor
							iterator(const iterator& itr) : m_ptr(itr.m_ptr){
									/*empty*/
							}
							/// Assign operator
							iterator& operator=(const iterator& rhs){
									m_ptr = rhs.m_ptr;
							}

							reference operator *(void) const{
								 return *m_ptr;
							}
							// ++it
							iterator operator++(){
									return ++m_ptr;
							}
							// it++
							iterator operator++(int){
									auto temp(*this);
									++m_ptr;
									return temp;
							}
							// --it
							iterator operator--(){
									return --m_ptr;
							}
							// it--
							iterator operator--(int){
									auto temp(*this);
									--m_ptr;
									return temp;
							}

						 bool operator==(const iterator& rhs) const{
							return m_ptr == rhs.m_ptr;
						 }
						 bool operator!=(const iterator& rhs) const{
							return m_ptr != rhs.m_ptr;
						 }

					private:
							pointer m_ptr;

			};
			class const_iterator{
					private:
			};
			//CONSTRUTORES E DESTRUTORES
			/*Parâmetros
				count - o tamanho da lista.
				valor - o valor para inicializar a lista com.
				fist, last - o intervalo para copiar os elementos de.
				other - outra lista a ser usada como fonte para inicializar os elementos da lista com.
				ilist - lista inicializadora para inicializar os elementos da lista com.*/

			//1- Construtor Default que cria uma lista vazia.
			vector(void): m_size(SIZE){
				/*empty*/
			}
			//2- Constrói a lista com instâncias inseridas por padrão de T.
			explicit vector(size_type count){
				m_size = count;
			}
			//3- Constrói a lista com o conteúdo do intervalo [first, last].
			template< typename InputIt >
			vector( InputIt first, InputIt last ){
					//dificuldades em implementar

			}
			//4- Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
			vector(const vector& other ){
				m_size = other.m_size;
				std::copy(&other.m_data[0], &other.m_data[m_size], &m_data[0]);
			}
			//5- Constrói a lista com o conteúdo da lista inicializadora init.
			vector(const std::initializer_list<T> il ){
				std::copy(il.begin(), il.end(), &m_data[0]);
        m_size = il.size();
			}
			//6- Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é desalocado.
			//Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos
			~vector(void){
				//delete [] m_data;
			}
			/*7- Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
			os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
			estado não especificado depois*/
			vector& operator=( const vector& other ){
				m_size = other.m_size;
				std::copy(&other.m_data[0], &other.m_data[m_size], &m_data);
			}
			//8- Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
			vector& operator=( std::initializer_list<T> ilist ){
				std::copy(ilist.begin(), ilist.end(), &m_data[0]);
        m_size = ilist.size();
			}

			reference operator[](size_type pos){
          return m_data[pos];
      }

			reference at(size_type pos){
					if( pos < 0 or pos >= m_size)
							throw std::out_of_range("[array::at()] Acesso fora dos limites do vetor");
					return m_data[pos];
			}

			size_type size(void) const{
					return m_size;
			}

			bool empty(void) const{
					return m_size ==0;
			}

			void clear() {
				size_type i;
				for(i = 0; i < m_size; i++){
					m_data[i].~T();
				}

				m_size = 0;
			}

			void reserve (size_type new_cap) {
				if(new_cap > capacity()){
					value_type new_vector[new_cap];
					std::memmove(new_vector, m_data, new_cap*sizeof(T));
					clear();
					m_size = new_cap;
					std::memmove(m_data, new_vector, new_cap*sizeof(T));
				}
			}

			void shrink_to_fit(){
				if(m_capacity > m_size){
					m_capacity = m_size;
				}
			}

			void push_front(const T & value){
				auto i = m_size+1;
				reserve(i);
				value_type new_vector[m_size];
				std::memmove(new_vector, m_data, m_size*sizeof(T));
				clear();
				m_size = i;
				m_data[0] = value;
				std::memmove(&m_data[1], new_vector, m_size*sizeof(T));
			}

			void push_back(const T & value){
				auto i = m_size+1;
				reserve(i);
				value_type new_vector[m_size];
				std::memmove(new_vector, m_data, m_size*sizeof(T));
				clear();
				m_size = i;
				std::memmove(m_data, new_vector, m_size*sizeof(T));
				m_data[i-1] = value;
			}

			void pop_back(){
				//m_data[m_size-1].~T();
				if(m_size-1 >= 0){
						m_size--;
				}
			}

			void pop_front(){
				if(m_size-1 >= 0){
					value_type new_vector [m_size];
					std::memmove(new_vector, &m_data[1], m_size*sizeof(T));
					m_size--;
					std::memmove(m_data, new_vector, m_size*sizeof(T));
				}
			}

			const T & back() const {
				return m_data[m_size-1];
			}

			const T & front() const {
				return m_data[0];
			}

			bool operator==(const vector<T, SIZE>& rhs){
					if(m_size != rhs.m_size)
							return false;
					return std::equal(&rhs.m_data[0], &rhs.m_data[m_size], &m_data[0]);
			}

			bool operator!=(const vector<T, SIZE>& rhs){
					if(m_size != rhs.m_size)
							return true;
					return std::equal(&rhs.m_data[0], &rhs.m_data[m_size], &m_data[0]);
			}

			size_type capacity( void ){
				m_capacity = (size_type) std::distance(&m_data[0], &m_data[m_size]);
				return std::distance(&m_data[0],&m_data[m_size]);
			}

			iterator begin(void){
					return iterator(&m_data[0]);
			}
			iterator end(void){
					return iterator(&m_data[m_size]);
			}

			const_iterator cbegin(void) {
				return const_iterator(&m_data[0]);
			}

			const_iterator cend(void){
				return const_iterator(&m_data[m_size]);
			}
		};
}
int main(){
	sc::vector<char, 3> a = {'c', 's','a','b'};
	sc::vector<char> b (a.begin(),a.end());


	std::cout << a.capacity() << std::endl;
	a.push_back('l');
	for(auto it = a.begin(); it!=a.end(); it++){
			std::cout << *it << "\n";
	}
	std::cout << a.capacity() << "\n";
	a.pop_front();
	for(auto it = a.begin(); it!=a.end(); it++){
			std::cout << *it << "\n";
	}
	std::cout << "\n";
	std::cout << a.capacity() << std::endl;
	std::cout<< a.back() << std::endl;
	std::cout<< a.front() << std::endl;
	std::cout<< a.back() << std::endl;

	//std::cout << a.capacity() << std::endl;
	/*for(auto it = b.begin(); it!=b.end(); it++){
			std::cout << *it << "\n";
	}*/
	return 0;
}
