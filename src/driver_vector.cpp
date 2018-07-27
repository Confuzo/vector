#include "../include/vector.h"
int main(){
	//construtor com lista
	sc::vector<int> a {1,2,3};
	sc::vector<int> b (a.begin(), a.end());
	//auto teste = a.begin() + 1;
	std::cout << "Testando "<< *(a.begin()+1) << std::endl;
	return 0;
}