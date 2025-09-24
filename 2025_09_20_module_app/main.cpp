#include "io.hpp"
#include "generator.hpp"
#include "sortings.hpp"
#include <vector>

int main(){

	const int size = biv::readSize();

	std::vector<int> array = biv::gen::generateArray(size);

	biv::showArray("Массив до сортировки:", array.data(), size);

	biv::sortings::insertingSort(array.data(),size);

	biv::showArray("Массив после сортировки:", array.data(),size);

	return 0;
}
