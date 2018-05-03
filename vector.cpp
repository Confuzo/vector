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
			size_type m_size; //!< Stores the array size.
      		value_type m_data[ SIZE ]; //the storage area
					size_type m_capacity;
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
					public:
						typedef const T*                              pointer;
						typedef const std::ptrdiff_t                  diference_type;
						typedef const T                               value_type;
						typedef const T&                              reference;
						typedef const std::bidirectional_iterator_tag iterator_category;

						//constructor (empty and single value)
						const_iterator(pointer ptr=nullptr) : m_ptr(ptr){
								/*empty*/
						}
						//destructor
						~const_iterator() = default;
						//copy constructor
						const_iterator(const const_iterator& itr) : m_ptr(itr.m_ptr){
								/*empty*/
						}
						/// Assign operator
						const_iterator& operator=(const const_iterator& rhs){
								m_ptr = rhs.m_ptr;
						}

						reference operator *(void) const{
								return *m_ptr;
						}
						// ++it
						const_iterator operator++(){
								return ++m_ptr;
						}
						// it++
						const_iterator operator++(int){
								auto temp(*this);
								++m_ptr;
								return temp;
						}
						// --it
						const_iterator operator--(){
								return --m_ptr;
						}
						// it--
						const_iterator operator--(int){
								auto temp(*this);
								--m_ptr;
								return temp;
						}

						bool operator==(const const_iterator& rhs) const{
						return m_ptr == rhs.m_ptr;
						}
						bool operator!=(const const_iterator& rhs) const{
						return m_ptr != rhs.m_ptr;
						}

					private: pointer m_ptr;

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
			~vector(void) = default;

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

			void shrink_to_fit(){
				if(m_capacity > m_size){
					m_capacity = m_size;
				}
			}

			void reserve (size_type new_cap) {
				if(new_cap > capacity()){
					value_type new_vector[new_cap];
					std::memmove(new_vector, m_data, new_cap*sizeof(T));
					clear();
					m_size = new_cap;
					m_capacity = m_size;
					std::memmove(m_data, new_vector, new_cap*sizeof(T));
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
				m_size--;
			}

			void pop_front(){
				value_type new_vector [m_size];
				std::memmove(new_vector, &m_data[1], m_size*sizeof(T));
				m_size--;
				std::memmove(m_data, new_vector, m_size*sizeof(T));
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

			size_type capacity( void ) const{
				return std::distance(&m_data[0],&m_data[m_size]);
			}

			iterator begin(void){
					return iterator(&m_data[0]);
			}
			iterator end(void){
					return iterator(&m_data[m_size]);
			}

			const_iterator cbegin(void) const{
				return const_iterator(&m_data[0]);
			}

			const_iterator cend(void) const{
				return const_iterator(&m_data[m_size]);
			}
			iterator insert(iterator pos, const T& value){
				auto i = m_size+1;
				reserve(i);
				iterator aux = begin();
				auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);
				value_type new_vector [m_size];
				std::memmove(new_vector, m_data, m_size*sizeof(T));
				if(index < m_size){
					m_data[index] = value;
				}
				std::memmove(&m_data[index+1], new_vector, m_size*sizeof(T));

				return pos;
			}

			template <typename InItr>
			iterator insert(iterator pos, InItr first, InItr last){
			}

			iterator insert(iterator pos, std::initializer_list<T> ilist){
				auto i = m_size + ilist.size();
				reserve(i);
				iterator aux = begin();
				auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-2*sizeof(T);
				value_type new_vector [m_size];
				std::memmove(new_vector, m_data, m_size*sizeof(T));
				if(index < m_size){
					std::copy(ilist.begin(), ilist.end(), &m_data[index]);
				}
				std::memmove(&m_data[index+ilist.size()], new_vector, m_size*sizeof(T));

				return pos;
			}

			iterator erase(iterator pos){
				iterator aux = begin();
				auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-2*sizeof(T);
				value_type new_vector [m_size];
				std::memmove(new_vector, &m_data[index+1], m_size*sizeof(T));
				std::memmove(&m_data[index], new_vector, m_size*sizeof(T));
				m_size--;
				return aux;
			}

			iterator erase(iterator first, iterator last){
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

			void assign(size_type count, const T & value){
				for (size_type i = 0; i< count; i++){
					m_data[i] = value;
				}
				m_size = count;
			}

			void assign(std::initializer_list<T> ilist){
				std::copy(ilist.begin(), ilist.end(), &m_data[0]);
				m_size = ilist.size();
			}
		};
}
int main(){
	sc::vector<char> a = {'c', 's','a','b'};
	sc::vector<char> b (a.begin(),a.end());
	sc::vector<char> c;
	c.assign(7,'l');

	sc::vector<char>::iterator it = a.begin();
	//sc::vector<char>::iterator cit = a.cbegin();
	//*it = 'b';
	//*cit = 'g';

	std::cout << &it <<"\n";

	a.insert(it, 'h');

	std::cout << &it <<"\n";

	std::cout << "----------------------\n";

	std::cout << a.capacity() << std::endl;

	for(auto it = a.begin(); it!=a.end(); it++){
			std::cout << *it << "\n";
	}
	a.erase(a.begin(), a.end());
	for(auto it = a.begin(); it!=a.end(); it++){
			std::cout << *it << "\n";
	}
	for(auto it = c.begin(); it!=c.end(); it++){
			std::cout << *it << "\n";
	}
	//std::cout << a.capacity() << std::endl;
	/*for(auto it = b.begin(); it!=b.end(); it++){
			std::cout << *it << "\n";
	}*/
	return 0;
}
