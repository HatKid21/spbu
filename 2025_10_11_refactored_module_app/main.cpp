#include "io.hpp"
#include "sortings.hpp"

int main(){
	int ar[] = {1,5,2,3,8,10,11,6};
	const int arraySize = sizeof(ar) / sizeof(ar[0]);
	
	io::showArray("Массив до сортировки",ar,arraySize);
	
	sort::mergeSort(ar,ar+arraySize);

	io::showArray("Массов после сортировки",ar,arraySize);	
}
