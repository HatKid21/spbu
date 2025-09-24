#include "generator.hpp"

#include <random>
#include <vector>

std::vector<int> biv::gen::generateArray(int size){
	std::vector<int> array;
	array.reserve(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,1000);
	while (size--){
		array.push_back(dist(gen));
	}
	return array;
}
