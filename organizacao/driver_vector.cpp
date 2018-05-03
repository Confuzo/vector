#include "vector.h"
int main(){
	sc::vector<char> a = {'c', 's','a','b'};
	sc::vector<char> b (a.begin(),a.end());

	sc::vector<char>::iterator it = a.begin();
	sc::vector<char>::const_iterator cit = a.cbegin();
	//*it = 'b';
	//*cit = 'g';	
	a.insert(it, {'d','u','l'});
	//a.insert(++it, 'h');

	std::cout << "----------------------\n";
	std::cout << a.capacity() << std::endl;
	std::cout << "----------------------\n";

	for(; it!=a.end(); it++){
			std::cout << *it << "\n";
	}
	//std::cout << a.capacity() << std::endl;
	/*for(auto it = b.begin(); it!=b.end(); it++){
			std::cout << *it << "\n";
	}*/
	return 0;
}