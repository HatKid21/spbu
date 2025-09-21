#include "sortings.hpp"

void biv::sortings::insertingSort(int* const ar, const	int size){
	for (int* i = ar + 1; i < ar + size; i++){
		int cur = *i;
		int* j = i;
		while (j > ar && *(j-1) > cur){
			*j = *(j-1);
			j--;
		}
		*j = cur;
	}
}
