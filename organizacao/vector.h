#include "iterator.h"
#include "const_iterator.h"
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>
namespace sc{
	template <typename T, size_t SIZE=0>
	class vector{
        public:
            using iterator = iterator<T>
            using const_iterator = const_iterator<T>
        
		typedef T value_type;
        typedef size_t size_type;
        typedef T* pointer;
        typedef T& reference;

		private:
			size_type m_size; //!< Stores the array size.
      		value_type m_data[ SIZE ]; //the storage area
		
        public:
            
			//CONSTRUTORES E DESTRUTORES
			/*Parâmetros
				count - o tamanho da lista.
				valor - o valor para inicializar a lista com.
				fist, last - o intervalo para copiar os elementos de.
				other - outra lista a ser usada como fonte para inicializar os elementos da lista com.
				ilist - lista inicializadora para inicializar os elementos da lista com.*/

			//1- Construtor Default que cria uma lista vazia.
			vector(void): m_size(SIZE);
			//2- Constrói a lista com instâncias inseridas por padrão de T.
			explicit vector(size_type count);
			//3- Constrói a lista com o conteúdo do intervalo [first, last].
			template< typename InputIt >
			vector( InputIt first, InputIt last );
			//4- Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
			vector(const vector& other );
			//5- Constrói a lista com o conteúdo da lista inicializadora init.
			vector(const std::initializer_list<T> il );
			//6- Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é desalocado.
			//Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos
			~vector(void) = default;

			/*7- Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
			os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
			estado não especificado depois*/
			vector& operator=( const vector& other );
			//8- Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
			vector& operator=( std::initializer_list<T> ilist );

			reference operator[](size_type pos);

			reference at(size_type pos);

			size_type size(void) const;

			bool empty(void) const;

			void clear() ;

			void reserve (size_type new_cap) ;

			void push_front(const T & value);

			void push_back(const T & value);

			void pop_back();

			void pop_front();

			const T & back() const ;

			const T & front() const ;

			bool operator==(const vector<T, SIZE>& rhs);

			bool operator!=(const vector<T, SIZE>& rhs);

			size_type capacity( void ) const;

			iterator begin(void);

			iterator end(void);

			const_iterator cbegin(void) const;

			const_iterator cend(void) const;
			iterator insert(iterator pos, const T& value);

			template <typename InItr>
			iterator insert(iterator pos, InItr first, InItr last);

			iterator insert(iterator pos, std::initializer_list<T> ilist);
           
		};
        
}
