#include "../include/vector.h"
int main(){
	//construtor com lista
	sc::vector<int> a {1,2,3};
	sc::vector<int> b (a.begin(), a.end());
	//auto teste = a.begin() + 1;
	//std::cout << "Testando "<< *(a.begin()+1)<< " " << *(a.end()) << std::endl;
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	return 0;
}