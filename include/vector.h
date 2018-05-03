#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>

namespace sc{
	template <typename T>
	/**@title Classe vector, comporta todas as funções que podem ser usadas e demais classes de iteradores de tipo abstrato*/
	class vector{
        
        typedef T value_type;
		typedef size_t size_type;
		typedef T* pointer;
		typedef T& reference;
		
        public:

        	const static size_t SIZE = 0;
			/**@title Classe iterator, comporta todas as funções que podem ser usadas por iteradores do tipo do vector*/
            class iterator{
	            public: //iterator traits
	                    typedef T*                              pointer;
	                    typedef std::ptrdiff_t                  diference_type;
	                    typedef T                               value_type;
	                    typedef T&                              reference;
	                    typedef std::bidirectional_iterator_tag iterator_category;
	                   
					    /**@title Construtor da classe iterator 
						 * @param (empty and single value)*/
	                    iterator(pointer ptr=nullptr) : m_ptr(ptr){}
	                    
						/**@title Destrutor da classe iterator 
						 * @param (empty and single value)*/
	                    ~iterator();
	                    
						/**@title Construtor cópia da classe iterator 
						 * @param (const iterator& itr)*/
	                    iterator(const iterator& itr);
	                   
					    /**@title Operador = da classe iterator 
						 * @param (const iterator& rhs)*/
	                    iterator& operator=(const iterator& rhs);
						
						/**@title Operador * da classe iterator 
						 * @param (const iterator& rhs)
						 * @return iterator*/
	                    reference operator *(void) const;
	            
						/**@title Operador ++it da classe iterator 
						 * @param (void)
						 * @return reference*/
	                    iterator operator++();
	                    
						/**@title Operador it++ da classe iterator 
						 * @param (void)
						 * @return iterator*/
	                    iterator operator++(int);
	                    
						/**@title Operador --it da classe iterator 
						 * @param (void)*/
	                    iterator operator--();
	                    
						/**@title Operador it-- da classe iterator 
						 * @param (void)
						 * @return iterator*/
	                    iterator operator--(int);
						
						/**<@title Operador == da classe iterator 
						 * @param (const iterator& rhs)
						 * @return boolean*/
	                    bool operator==(const iterator& rhs) const;
						
						/**<@title Operador != da classe iterator 
						 * @param (const iterator& rhs)
						 * @return boolean*/
	                    bool operator!=(const iterator& rhs) const;
	            
				private:
	                    pointer m_ptr;

   			 };
			/**@title Classe const iterator, comporta todas as funções que podem ser usadas por iteradores constantes do tipo do vector*/
			class const_iterator{
	            public:
	                typedef const T*                              pointer;
	                typedef const std::ptrdiff_t                  diference_type;
	                typedef const T                               value_type;
	                typedef const T&                              reference;
	                typedef const std::bidirectional_iterator_tag iterator_category;

	                
					/**@title Construtor da classe const_iterator 
					 * @param (empty and single value)*/
	                const_iterator(pointer ptr=nullptr) : m_ptr(ptr){}
	                
					/**@title Destrutor da classe const_iterator 
					 * @param (empty and single value)*/
	                ~const_iterator();
	                
					 /**@title Construtor cópia da classe const_iterator 
					  * @param (const iterator& itr)*/
	                const_iterator(const const_iterator& itr);
	                
					/**@title Operador = da classe const_iterator 
					  *@param (const iterator& rhs)
					  *@return const_iterator*/
	                const_iterator& operator=(const const_iterator& rhs);
					
					/**@title Operador * da classe const_iterator 
					  *@param (void)
					  *@return const_iterator*/
	                reference operator *(void) const;
	                
					/**@title Operador ++it da classe const_iterator 
					 *@param (void)
					 *@return reference*/
	                const_iterator operator++();
	                
					/**@title Operador it++ da classe const_iterator 
					 *@param (void)
					 *@return const_iterator*/
	                const_iterator operator++(int);
	               
					/**@title Operador --it da classe const_iterator 
					 *@param (void)
					 *@return const_iterator*/
	                const_iterator operator--();

					/**@title Operador it-- da classe const_iterator 
					 *@param (void)
					 *@return const_iterator*/
	                const_iterator operator--(int);

					/**@title Operador == da classe const_iterator 
					 *@param (const iterator& rhs)
					 *@return boolean*/
	                bool operator==(const const_iterator& rhs) const;
					
					/**@title Operador != da classe const_iterator 
					 *@param (const iterator& rhs)
					 **@return boolean*/
	                bool operator!=(const const_iterator& rhs) const;

	            private: 
	                pointer m_ptr;

    		};
			//CONSTRUTORES E DESTRUTORES

			/**@title Construtor Default que cria um vetor vazio.*/
			vector(void);
			
			/**@title Constrói o vetor com instâncias inseridas por padrão de T. 
			 * @param size_type count - o tamanho do vetor.
			*/
			vector(size_type count);
			
			/**@title Constrói o vetor com o conteúdo do intervalo [first, last].*/
			template< typename InputIt >
			vector( InputIt first, InputIt last );
			
			/**@title Construtor de cópia. Constrói o vetor com a cópia profunda do conteúdo de outro.
			 * @param const vector& other - vetor cópia.
			*/
			vector(const vector& other );
			
			/**@title Constrói o vetor com o conteúdo da lista inicializadora init.
			 * @param const std::initializer_list<T> il - lista inicializadora para inicializar os elementos da lista com.
			*/ 
			vector(const std::initializer_list<T> il );
			
			/**@title Destrói o vetor. O destrutor é chamado e o armazenamento usado é desalocado.*/
			//Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos
			~vector(void);

			/**@title Operador = (de atribuição) da classe vector, receber um outro vector 
			 * @param const vector& other
			*/
			vector& operator=( const vector& other );
			
			/**@title Operador = (de atribuição) da classe vector, receber uma lista inicializadora 
			 * @param std::initializer_list<T> ilist
			*/
			vector& operator=( std::initializer_list<T> ilist );

			/**@title Operador [] (indexação) da classe vector, receber uma posição index to tipo size_type
			 * @param size_type pos
			 * @return retorna uma referencia reference
			*/
			reference operator[](size_type pos);

			/**@title Função at (indexação) da classe vector, receber uma posição index to tipo size_type
			 * @param size_type pos
			 * @return retorna uma referencia reference
			*/
			reference at(size_type pos);

			/**@title função size da classe vector, retorna o tamanho size do vetor
			 * @param void
			 * @return size_type size do vetor
			*/
			size_type size(void) const;

			/**@title função empty da classe vector, retorna verdadeiro se o vetor estiver vazio e falso se não vazio
			 * @param void
			 * @return boolean
			*/
			bool empty(void) const;
			
			/**@title função clear da classe vector, limpa o vetor, mas não o desaloca da memoria
			 * @param void
			 * @return viod
			*/
			void clear() ;
			
			/**@title função reserve da classe vector, reserva pra um vetor já alocado o tamanho new_cap passado por parametro
			 * @param size_type new_cap
			 * @return void
			*/
			void reserve (size_type new_cap) ;

			/**@title função push_front da classe vector, insere um elemento na primeira posição do vetor
			 * @param const T & value
			 * @return void
			*/
			void push_front(const T & value);

			/**@title função push_back da classe vector, insere um elemento na ultima posição do vetor
			 * @param const T & value
			 * @return void
			*/
			void push_back(const T & value);

			/**@title função pop_back da classe vector, exclui o elemento da ultima posição do vetor
			 * @param void
			 * @return void
			*/
			void pop_back();

			/**@title função pop_front da classe vector, exclui o elemento da primeira posição do vetor
			 * @param void
			 * @return void
			*/
			void pop_front();

			/**@title função back da classe vector, retorna o elemento da ultima posição do vetor
			 * @param void
			 * @return void
			*/
			const T & back() const ;
			
			/**@title função front da classe vector, retorna o elemento da primeira posição do vetor
			 * @param void
			 * @return void
			*/
			const T & front() const ;

			/**@title Operador == da classe vector, compara dois vetores e retorna true se eles forem iguais e falso se não
			 *@param const vector<T>& rhs
			 *@return boolean*/
			bool operator==(const vector<T>& rhs);

			/**@title Operador != da classe vector, compara dois vetores e retorna true se eles forem diferentes e falso se não
			 *@param const vector<T>& rhs
			 *@return boolean*/
			bool operator!=(const vector<T>& rhs);

			/**@title função capacity da classe vector, retorna a capacidade total do vetor
			 *@param void
			 *@return size_type capacity*/
			size_type capacity( void ) const;

			/**@title função begin da classe vector, retorna um iterator que aponta para posição inicial do vetor
			 *@param void
			 *@return iterator it*/
			iterator begin(void);

			/**@title função end da classe vector, retorna um iterator que aponta para posição final +1 do vetor
			 *@param void
			 *@return iterator it*/
			iterator end(void);

			/**@title função cbegin da classe vector, retorna um const_iterator que aponta para posição inicial do vetor
			 *@param void
			 *@return const_iterator it*/
			const_iterator cbegin(void) const;

			/**@title função cend da classe vector, retorna um const_iterator que aponta para posição inicial do vetor
			 *@param void
			 *@return const_iterator it*/
			const_iterator cend(void) const;

			/**@title função insert da classe vector, como como parametro um iterator e um valor, e insere o valor na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do novo elemento
			 *@param iterator pos, const T& value
			 *@return iterator*/
			iterator insert(iterator pos, const T& value);

			/**@title função insert (com range) da classe vector, como como parametro um iterator e um um range, e insere os valores do range na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do primeiro elemento do range
			 *@param iterator pos, InItr first, InItr last
			 *@return iterator*/
			template <typename InItr>
			iterator insert(iterator pos, InItr first, InItr last);

			/**@title função insert (com list) da classe vector, como como parametro um iterator e uma lista, e insere os valores da lista na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do primeiro elemento da lista
			 *@param iterator pos, std::initializer_list<T> ilist
			 *@return iterator*/
			iterator insert(iterator pos, std::initializer_list<T> ilist);
			
			/**@title função erase da classe vector, como como parametro um iterator, e deleta o valor na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do novo elemento da posição
			 *@param iterator pos
			 *@return iterator*/
			iterator erase(iterator pos);
			
			/**@title função erase (com range) da classe vector, como como parametro um range, e deleta os valores do range 
			 * e retorna um iterator para o endereço do primeiro elemento do range
			 *@param iterator first, iterator last
			 *@return iterator*/
			iterator erase(iterator first, iterator last);
			
			/**@title função assign da classe vector, substitui o conteúdo com cópias de contagem do valor 
			 *@param size_type count, const T & value
			 *@return void*/
			void assign(size_type count, const T & value);

			/**@title função assign (com range) da classe vector, substitui o conteúdo da lista por cópias dos elementos no intervalo [primeiro; último). 
			 *@param InItr first, InItr last
			 *@return void*/
			template<typename InItr>
			void assign( InItr first, InItr last );

			/**@title função assign (com lista) da classe vector, substitui o conteúdo do vetor com os elementos da lista de inicializadores ilist. 
			 *@param std::initializer_list<T> ilist
			 *@return void*/
			void assign(std::initializer_list<T> ilist);
           	
           	private:
				size_type m_size; //!< Stores the array size.
      			value_type m_data[ SIZE ]; //the storage area
				size_type m_capacity;
		};
	#include "vector.inl"
}
#endif