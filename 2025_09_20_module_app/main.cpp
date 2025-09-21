#include "io.hpp"
#include "sortings.hpp"

int main(){
	int array[] = {1,8,2,5,3,11};
	const int size = sizeof(array) / sizeof(array[0]);

	biv::showArray("Массив до сортировки:", array, size);

	biv::sortings::insertingSort(array,size);

	biv::showArray("Массив после сортировки", array,size);

	return 0;
}
