#include "io.hpp"

#include <iostream>

void io::showArray(const char* const comment, int* ar, int size){
	std::cout << comment << "\n";
	for (int i = 0; i < size; i++){
		std::cout << *ar++ << " ";
	}
	std::cout << "\n";
}

