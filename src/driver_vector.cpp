#include "../include/vector.h"
int main(){
	//construtor com lista
	sc::vector<char> a = {'c', 's','a','b'};
	//construtor copia com ranges
	sc::vector<char> b (a.begin(),a.end());
	//construtor normal
	sc::vector<char> c;

	//iterator de a recebendo begin
	sc::vector<char>::iterator it_a = a.begin();
	//const_iterator de a recebendo cbegin
	sc::vector<char>::const_iterator cit_a = a.cbegin();
	//iterator de c recebendo begin
	sc::vector<char>::iterator it_c = c.begin();
	//const_iterator de c recebendo cbegin
	sc::vector<char>::const_iterator cit_c = c.cbegin();

	//size
	std::cout << "size a: " << a.size() << std::endl;
	//capacity
	std::cout << "capacity de a: "<< a.capacity() << std::endl;
	//reserve
	c.reserve(3);
	//empty
		if(c.empty()){
			std::cout<<"c está vazio!!!\n";
		}else{ 
			std::cout<<"c não está vazio!!!\n";
		}
	
	//push front
	c.push_front('a');
	//push back
	c.push_back('b');
	c.push_back('c');
	//pop front
	c.pop_front();
	//pop back
	c.pop_back();
	//back
	std::cout << "back element c: " << c.back() << std::endl;
	//front
	std::cout << "front element c: " << c.front() << std::endl;
	std::cout << "printando c com o iterator\n";
	for(; it_c!=c.end(); it_c++){
		std::cout << "iterator value c: "<< *it_c << "\n";
	}
	//clear
	c.clear();
	std::cout << "front element c: " << c.front() << std::endl;

	//inserindo lista
	a.insert(it_a, {'u','l'});
	//assign com range
	c.assign(a.begin(),a.end());
	
	std::cout << "printando c com o const_iterator\n";
	for(; cit_c!=c.cend(); cit_c++){
			std::cout << "const_iterator value: "<< *cit_c << "\n";
	}
	std::cout << "printando a com o const_iterator\n";
	for(; cit_a!=a.cend(); cit_a++){
			std::cout << "const_iterator value: "<< *cit_a << "\n";
	}
	return 0;
}