#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace sc{
	template <typename T, size_t SIZE=1> 
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
				//std::copy()
			}
			//8- Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
			vector& operator=( std::initializer_list<T> ilist ){

			}

			reference operator[](size_type pos){
                return m_data[pos];
            }
		};
}
int main(){
	sc::vector<char> v {'c', 's'};
	sc::vector<char> v2 (v);
	auto a = v2[1];
	std::cout << a << std::endl;
	return 0;
}