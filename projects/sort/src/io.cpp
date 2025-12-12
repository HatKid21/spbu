#include "io.hpp"

#include <iostream>

void hatkid::io::showArray(const char* const comment, int* ar, const int size) {
	std::cout << comment << "\n";
	
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << " ";
	}

	std::cout << "\n";
}
