#include <iostream>
#include <algorithm>
#include <initializer_list>
namespace sc
{
    template < typename T, size_t SIZE=0 >
    class array
    {
        //=== Alias
        typedef int value_type;
        typedef size_t size_type;
        typedef int* pointer;
        typedef int& reference;

        public:
            class iterator{

            };
            class const_iterator{

            };

            //basic constructor
            array( void ){
                m_size = SIZE; // stores the array size.
            }
            ~array( ){
                /* empty*/
            }
            //copy constructor 
            array(const array& original)
            {
                //copy all elements of original into 'this'
                std::copy(&original.m_data[0], &original.m_data[m_size], &m_data[0]);
                m_size = original.m_size;
            }
            //copy constructor with initializer list
            array(const std::initializer_list<T> & il){
                //copy all elements of original into 'this'
                std::copy(il.begin(), il.end(), &m_data[0]);
                m_size = il.size();
            }

            //escrever e ler index do vetor 
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
            bool operator==(const array<T, SIZE>& rhs){
                if(m_size != rhs.m_size)
                    return false;
                return std::equal(&rhs.m_data[0], &rhs.m_data[m_size], &m_data[0]);
            }
            //sobrecarga no operator <<
            friend std::ostream& operator<<(std::ostream& os, const sc::array<T, SIZE>& a){
                os<< "[";
                     for ( auto i(0u) ; i < a.m_size ; ++i )
                        os<< a.m_data[i] << " ";
                os<< "]\n";
                return os;
            }
        //private:
            size_type m_size; //!< Stores the array size.
            value_type m_data[ SIZE ]; //the storage area

    };
}
//template <typename T, size_t SIZE>
/*void print( const sc::array<T, SIZE>& a){
    std::cout << "[ ";
   // for ( sc::array::iterator it = a.begin() ; it != a.end() ; ++it )
        //std::cout << *it << " "; 
     for ( auto i(0u) ; i < a.m_size ; ++i )
        std::cout << a.m_data[i] << " ,";
       
    std::cout << " ]\n";
}*/

int main( void ){
    //sc::array a(4); // Construtor com 1 argumento.
    sc::array< int, 5> a { {1,2,3,4,5} };//original
    sc::array< int, 5> b( a ); // chamando o construtor cópia.

    //print( a );
    //print( b );

    a[0] = -1;
    a[1] = -2;
    try{
        a.at(5) = 10;
    }catch(std::out_of_range & ex){
        std::cout << ex.what() << "\n";
    }

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}


