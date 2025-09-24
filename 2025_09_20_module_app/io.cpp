#include "io.hpp"

#include <iostream>

void biv::showArray(const char* const comment, int* arr, const int size){
	std::cout << comment;
	for (int i = 0; i < size; i ++){
		std::cout << *(arr + i) << " ";
	}
	std::cout << "\n";
}

int biv::readSize(){
	std::cout << "Введите размер массива:";
	int n;
	std::cin >> n;
	return n;
}
