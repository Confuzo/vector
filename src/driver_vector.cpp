#include "../include/vector.h"
int main(){
	//construtor com lista
	sc::vector<int> a {1,2,3};
	//sc::vector<int> b (a.begin(), a.end());
	//auto teste = a.begin() + 1;
	//std::cout << "Testando "<< *(a.begin()+1)<< " " << *(a.end()) << std::endl;
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	a.push_front(0);
	a.push_back(4);
	std::cout << std::endl;
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	std::cout << std::endl;
	std::cout << "Capacidade " << a.capacity() << " tamanho "<< a.size()<< std::endl;
	a.pop_front();
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	std::cout << std::endl;
	a.insert(a.begin() + 2,5);
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	std::cout << std::endl;
	return 0;
}